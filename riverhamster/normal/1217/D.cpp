#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define File(s) stdin = freopen(s".in", "r", stdin), stdout = freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 5005;
int n, m;
int to[N], nt[N], hd[N], C[N], ec = 0, cnt = 0;
inline void addedge(int x, int y){
	++ec;
	to[ec] = y; nt[ec] = hd[x]; hd[x] = ec;
}

stack<int> S;
bool instk[N], fa[N];
int dfn[N], low[N], ID = 0, color[N];

void tarjan(int x){
	instk[x] = fa[x] = true; S.push(x);
	dfn[x] = low[x] = ++ID;
	for(int i=hd[x]; i; i=nt[i]){
		if(!dfn[to[i]]){
			C[i] = color[x] ^ 1; color[to[i]] = color[x] ^ 1;
			tarjan(to[i]); low[x] = min(low[x], low[to[i]]);
		}
		else if(instk[to[i]]){
			low[x] = min(low[x], dfn[to[i]]);
			if(fa[to[i]]) C[i] = color[x] ^ 1;
			else C[i] = color[to[i]];
		}
		else C[i] = 1;
	}
	// printf("%d dfn %d low %d\n", x, dfn[x], low[x]);
	if(dfn[x] == low[x]){
		++cnt;
		while(S.top() != x) instk[S.top()] = false, S.pop();
		instk[x] = false; S.pop();
	}
	fa[x] = false;
}

int main(){
	// File("d");
	in(n); in(m);
	for(int i=1, x, y; i<=m; i++) in(x), in(y), addedge(x, y);
	for(int i=1; i<=n; i++)
		if(!dfn[i]) color[i] = 1, tarjan(i);
	// printf("n = %d cnt = %d\n", n, cnt);
	if(cnt == n){
		puts("1");
		for(int i=1; i<=m; i++) printf("1 ");
		putchar('\n');
	}
	else{
		// printf("n = %d cnt = %d\n", n, cnt);
		puts("2");
		for(int i=1; i<=m; i++) printf("%d ", C[i] + 1);
		putchar('\n');
	}
	return 0;
}