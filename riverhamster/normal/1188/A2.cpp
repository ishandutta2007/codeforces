#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(IO_Filename) freopen(IO_Filename".in", "r", stdin), freopen(IO_Filename".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	while(isspace(ch = getchar()));
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
}
const int N = 1005, E = 2005;
int to[E], nt[E], hd[N], w[E], fa[N], l[N], lch[N], upl[N], deg[N], ext[N], tot = 0;
int m = 0, solx[100005], soly[100005], solv[100005];
int root;
inline void addedge(int x, int y, int wt){
	to[++tot] = y; nt[tot] = hd[x]; hd[x] = tot; w[tot] = wt; ++deg[y];
}
inline void addsol(int x, int y, int v){
	solx[++m] = x; soly[m] = y; solv[m] = v;
}
inline void addpath(int x, int y, int v){
	int ch = 0;
	if(x == root){
		for(int i=hd[x]; i; i=nt[i]){
			if(to[i] != y){
				if(ch == 0) ch = l[to[i]];
				else{upl[x] = l[to[i]]; break;}
			}
		}
		// if(upl[x] == 0) printf("ERROR!");
	}
	else for(int i=hd[x]; i && ch == 0; i=nt[i])
			if(to[i] != y && to[i] != fa[x]) ch = l[to[i]];
	addsol(ch, l[y], v/2); addsol(upl[x], l[y], v/2); addsol(ch, upl[x], -(v/2));
	x = y; y = lch[y]; v = -v; ch = 0;
	if(x == l[x]) return ;
	for(int i=hd[x]; i && ch == 0; i=nt[i])
		if(to[i] != y && to[i] != fa[x]) ch = l[to[i]];
	addsol(ch, l[y], v/2); addsol(upl[x], l[y], v/2); addsol(ch, upl[x], -(v/2));
}
void getleaf(int x){
	int last = 0;
	for(int i=hd[x]; i; i=nt[i]){
		if(to[i] == fa[x]) continue;
		fa[to[i]] = x; getleaf(to[i]);
		l[x] = l[to[i]]; lch[x] = to[i]; upl[to[i]] = last;
		last = l[x];
	}
	if(l[x] == 0) l[x] = x;
	if(to[hd[x]] != fa[x]) upl[to[hd[x]]] = last;
	else upl[to[nt[hd[x]]]] = last;
}
void dfs(int x){
	for(int i=hd[x]; i; i=nt[i]){
		if(to[i] == fa[x]) continue;
		addpath(x, to[i], w[i]);
		dfs(to[i]);
	}
}

int main(){
	// File("cf1188a2");
	// setbuf(stdout, nullptr);
	int n, x, y, wt;
	in(n);
	if(n == 2){
		in(wt); in(wt); in(wt);
		printf("YES\n1\n");
		printf("%d %d %d\n", 1, 2, wt);
		return 0;
	}
	for(int i=1; i<n; i++) in(x), in(y), in(wt), addedge(x, y, wt), addedge(y, x, wt);
	for(int i=1; i<=n; i++)
		if(deg[i] == 2){
			puts("NO");
			return 0;
		}
		else if(deg[i] >= 3) root = i;
	fa[root] = root; getleaf(root);
	dfs(root);
	puts("YES");
	printf("%d\n", m);
	for(int i=1; i<=m; i++) printf("%d %d %d\n", solx[i], soly[i], solv[i]);
	return 0;
}