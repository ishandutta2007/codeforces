#include<bits/stdc++.h>
using namespace std;

int get()
{
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n, m, k;
int a[105];

void init()
{
	n = get(), m = get(), k = get();
	for(int i = 1; i <= n; i++) a[i] = get();
}

bool solve()
{
	for(int i = 1; i < n; i++) {
		int nxt = max(a[i + 1] - k, 0);
		if(a[i] >= nxt) {
			m += a[i] - nxt;
			continue;
		}
		else {
			int dis = nxt - a[i];
			if(dis > m) return 0;
			else m -= dis;
		}
	}
	return 1;
}

int main()
{
	int T = get();
	while(T--) {
		init();
		bool ans = solve();
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}