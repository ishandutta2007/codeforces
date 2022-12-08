#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 21, inf = 0x3f3f3f3f;
int n, f[1 << N], ans, tmp[N], sum[1 << N], lim[N];
string s[N];
unordered_map<int, int> cnt[N], pre[N];

void qmax(int &x, int y) { x = max(x, y); }

int main() {
	n = get();
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) {
		int now = 0, mn = 0, mnn = inf;
		for(int j = 0; j < s[i].size(); j++) {
			now += ((s[i][j] == '(')? 1 : -1);
			if(now < mn) pre[i][mn] = cnt[i][mn], mn--;
			cnt[i][now]++, mnn = min(mnn, now);
		}
		pre[i][mn] = cnt[i][mn], tmp[i] = now, lim[i] = mnn;
	}
	for(int i = 1; i < 1 << n; i++)
		for(int j = 1; j <= n; j++)
			if(i >> (j - 1) & 1) sum[i] += tmp[j];
	memset(f, -0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 0; i < 1 << n; i++) {
		if(f[i] < 0) continue;
		int now = sum[i];
		for(int j = 1; j <= n; j++) {
			if(i >> (j - 1) & 1) continue;
			qmax(ans, f[i] + pre[j][-sum[i]]);
			if(sum[i] + lim[j] >= 0) qmax(f[i | (1 << (j - 1))], f[i] + pre[j][-sum[i]]);
		}
	}
	cout << ans;
	return 0;
}