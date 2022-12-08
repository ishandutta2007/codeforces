#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, m, p, up, ans, anc;
char tmp[65];
int s[N], bin[N], top, sum[1 << 16];

void update(int x) {
	top = 0;
	for(int i = 0; i < m; i++) if(s[x] >> i & 1) bin[top++] = i;
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i++) {
		if(i == x) continue;
		int res = 0;
		for(int j = 0; j < top; j++) {
			int u = bin[j];
			if(s[i] >> u & 1) res |= (1 << j);
		}
		sum[res]++;
	}
	for(int i = 0; i < top; i++)
		for(int j = 0; j < 1 << top; j++)
			if(!(j >> i & 1)) sum[j] += sum[j ^ (1 << (i))];
	int mx = -1, mp = 0;
	for(int i = 1; i < 1 << top; i++) {
		int tot = sum[i] + 1;
		if(tot * 2 >= n) {
			int cnt = 0;
			for(int j = 0; j < top; j++) if(i >> j & 1) ++cnt;
			if(cnt > mx) mx = cnt, mp = i;
		}
	}
	if(mx > anc) {
		anc = mx;
		int res = 0;
		for(int i = 0; i < top; i++) {
			if(mp >> i & 1) res |= 1ll << (bin[i]);
		}
		ans = res;
	}
}

signed main() {
	srand(time(NULL));
	n = get(), m = get(), p = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", tmp);
		for(int j = 0; j < m; j++) if(tmp[j] == '1') s[i] |= 1ll << j;
	}
	int Vegas = 64;
	while(Vegas--) update(rand() * rand() % n + 1);
	for(int i = 0; i < m; i++) printf("%lld", ans >> i & 1);
	return 0;
}