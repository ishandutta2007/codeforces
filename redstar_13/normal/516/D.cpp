#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define NN 100001
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline bool gn(INT&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}

vector<pii> adj[NN];
INT mx[NN][2];

inline void insert(int u, INT x) {
	if(x>mx[u][1]) {
		mx[u][1]=x;
		if(mx[u][1]>mx[u][0]) swap(mx[u][0], mx[u][1]);
	}
}

inline void dfs(int u, int fa=0) {
	for(pii e: adj[u]) {
		int v=e.x, w=e.y;
		if(v!=fa) {
			dfs(v, u);
			insert(u, mx[v][0]+w);
		}
	}
}

inline void rdfs(int u, int fa=0, INT up=0) {
	insert(u, up);
	for(pii e: adj[u]) {
		int v=e.x, w=e.y;
		if(v!=fa) {
			if(mx[u][0]==mx[v][0]+w) rdfs(v, u, mx[u][1]+w);
			else rdfs(v, u, mx[u][0]+w);
		}
	}
}

int pa[NN];

inline void Dfs(int u, int fa=0) {
	for(pii e: adj[u]) {
		int v=e.x;
		if(v!=fa) {
			Dfs(v, u);
			pa[v]=u;
		}
	}
}

int root[NN], sz[NN], id[NN];
inline int find(int u) {return root[u]==u ? u : root[u]=find(root[u]);}

int main() {
	register int i=1;
	int n, u, v, w, m, ans, st, ed;
	INT L;
	
	gn(n);
	for(; i<n; i++) {
		gn(u), gn(v), gn(w);
		adj[u].push_back(pii(v, w));
		adj[v].push_back(pii(u, w));
		id[i]=i;
	}
	id[i]=i;
	
	dfs(1);
	rdfs(1);
	
	sort(id+1, id+n+1, [](int u, int v) {return *mx[u]<*mx[v];});
	
	Dfs(id[1]);
	gn(m);
	while(m--) {
		gn(L);
		
		ans=0;
		for(i=1; i<=n; i++) root[i]=i, sz[i]=0;
		for(st=n, ed=n; st; st--) {
			while(*mx[id[ed]]-*mx[id[st]]>L) sz[find(id[ed--])]--;
			smax(ans, ++sz[id[st]]);
			root[id[st]]=pa[id[st]];
			sz[pa[id[st]]]+=sz[id[st]];
		}
		print(ans); putchar('\n');
	}
}