#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5E5 + 10, MAXM = 5E5 + 10;

int n, m, P;
char s[MAXN];
int tail, que[MAXN];
int pre[MAXN], nex[MAXN], par[MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &P);
	scanf("%s", s + 1);
	nex[0] = 1, pre[n + 1] = n;
	tail = 0;
	for (int i = 1; i <= n; ++i){
		pre[i] = i - 1, nex[i] = i + 1;
		if (s[i] == '(')
			que[tail++] = i;
		else{
			par[i] = que[--tail];
			par[que[tail]] = i;
		}
	}

	getchar();
	for (int u = P, i = 0; i < m; ++i){
		char ins = getchar();
		if (ins == 'L')
			u = pre[u];
		else if (ins == 'R')
			u = nex[u];
		else{
			int v = par[u];
			if (v < u)
				swap(u, v);
			nex[pre[u]] = nex[v];
			pre[nex[v]] = pre[u];
			u = nex[v] <= n ? nex[v] : pre[u];
		}
	}
	for (int u = nex[0]; u <= n; u = nex[u])
		putchar(s[u]);
	puts("");
	return 0;
}