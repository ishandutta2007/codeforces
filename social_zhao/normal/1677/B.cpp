#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
int n, m, sum[N], pre[N], now[N], ans[N];
char s[N];

void solve() {
	n = get(), m = get();
	for(int i = 0; i <= n * m; i++) sum[i] = pre[i] = now[i] = 0;
	scanf("%s", s + 1);
	for(int i = 1; i <= n * m; i++) sum[i] = sum[i - 1] + s[i] - '0';
	int col = 0;
	for(int i = 1; i <= n * m; i++) {
		if(s[i] == '1') {
			if(!now[i % m]) now[i % m] = 1, ++col;
		}
		if(sum[i] - sum[max(0, i - m)]) pre[i] = 1;
		if(i >= m) pre[i] += pre[i - m];
		ans[i] = col + pre[i];
	}
	for(int i = 1; i <= n * m; i++) cout << ans[i] << " "; cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	int T = get();
	while(T--) solve();
	return 0;
}