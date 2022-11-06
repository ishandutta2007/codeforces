//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, k;
int a[N], pre[N], nxt[N], pos[N], ans[N];
int u = 1;

int main() {
	scanf("%d%d", &n, &k);
	int Num = n;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		pre[i] = i - 1;
		nxt[i] = i + 1;
		if(i == n) nxt[i] &= 0;
	}
	while(true) {
		while(ans[pos[n]]) --n;
		if(!n) break;
		int _ = pos[n];
		ans[_] = u;
		int Pre = pre[_], Nxt = nxt[_];
		for(int i=1;i<=k&&Pre;i++) ans[Pre] = u, Pre = pre[Pre];
		for(int i=1;i<=k&&Nxt;i++) ans[Nxt] = u, Nxt = nxt[Nxt];
		pre[Nxt] = Pre;
		nxt[Pre] = Nxt;
		u ^= 3;
	}
	for(int i=1;i<=Num;i++) printf("%d", ans[i]);
	return 0;
}