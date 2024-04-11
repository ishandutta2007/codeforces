#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 300019
#define maxm 600019
#define ll long long int 
using namespace std;

int n, m, a, b;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int low[maxn], dfs[maxn];
int t = 0;
int DFS(int x, int fa){
	dfs[x] = low[x] = ++t;
	bool f = 1;
	erep(i, x){
		int op = e[i].to;
		if (f && op == fa) {f = 0; continue;}
		if (dfs[op]) low[x] = min(low[x], dfs[op]);
		else low[x] = min(low[x], DFS(op, x));
		//low[x] = min((low[op]) ? low[op] : DFS(op, x), low[x]);
	}
	return low[x];
}

bool visa[maxn], visb[maxn];
int sa = 0, sb = 0;
void DFS2(int x){
	if (visa[x]) return;
	sa++;
	visa[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (!visa[op]) DFS2(op);
	}
}
void DFS3(int x){
	if (visb[x]) return;
	sb++;
	visb[x] = 1;
	erep(i, x){
		int op = e[i].to;
		if (!visb[op]) DFS3(op);
	}
}

void recover(){
	t = sa = sb = 0; cnt = 1;
	rep(i, 1, n) h[i] = dfs[i] = low[i] = visa[i] = visb[i] = 0;
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d%d", &n, &m, &a, &b);
		rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
		int root = 1;
		rep(i, 1, n) if (i != a && i != b) {root = i; break;} 
		DFS(root, root);
		//if (low[a] != dfs[a] || low[b] != dfs[b]) printf("0\n");
		//else {
		int ans1 = -1;
		visa[a] = 1;
		erep(i, a){
			int op = e[i].to, _sa = sa;
			bool f = (!visa[b]) ? 1 : 0;
			if (low[op] >= dfs[a]) DFS2(op);
			if (f && visa[b]) ans1 = n - (sa - _sa) - 1; 
		}
		if (ans1 == -1) ans1 = sa;
		
		int ans2 = -1;
		visb[b] = 1;
		erep(i, b){
			int op = e[i].to, _sb = sb;
			bool f = (!visb[a]) ? 1 : 0;
			if (low[op] >= dfs[b]) DFS3(op);
			if (f && visb[a]) ans2 = n - (sb - _sb) - 1;
		}
		if (ans2 == -1) ans2 = sb;
		printf("%lld\n", (ll)ans1 * ans2);
		//if (!visa[b] && !visb[a]) printf("%lld\n", (ll)numa * numb);
		//else if (visa[b]) printf("%lld\n", (ll)(n - numa - 1) * numb);
		//else if (visb[a]) printf("%lld\n", (ll)(n - numb - 1) * numa);
		//}
		recover();
	}
	return 0;
}