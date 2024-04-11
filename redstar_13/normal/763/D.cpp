#include<bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

#define NN 200111
VI adj[NN];
int n;
INT seed[NN<<1];
INT hs[NN];
int runs;
map<INT, int> mp;
int ans;
int now;
int cnt[NN<<1];
INT sum[NN];
int id[NN];

inline int get(INT u) {
	if(mp.count(u)) return mp[u];
	return mp[u] = ++runs;
}

inline void add(int id) {
	if(cnt[id]==0) now++;
	cnt[id]++;
}

inline void del(int id) {
	cnt[id]--;
	if(cnt[id]==0) now--;
}

int dfs(int u, int fa=0) {
	for(int v : adj[u]) if(v != fa) {
		dfs(v, u);
		sum[u] += hs[v];
	}
	id[u]=get(sum[u]);
	hs[u]=seed[id[u]];
	add(id[u]);
}

int val[NN];

void calc(int u, int fa=0, INT pre=0) {
	val[u] = now;
	if(val[ans]<val[u]) ans=u;
	for(int v : adj[u]) if(v != fa) {
		del(id[v]);
		INT A=sum[u]+pre; A=get(A);
		del(A);
		INT tmp=sum[u]-hs[v];
		tmp+=pre;
		tmp=get(tmp);
		INT cur=sum[v]+seed[tmp];
		cur=get(cur);
		add(cur);
		add(tmp);
		calc(v, u, seed[tmp]);
		
		del(tmp);
		del(cur);
		add(id[v]);
		add(A);
	}
}

int solve() {
	cin >> n;
	for(int i=0; i<n-1; i++) {
		int u, v; gn(u); gn(v);
		adj[u].pb(v); adj[v].pb(u);
	}
	for(int i=1; i<=2*n; i++) seed[i]=abs((INT)rand()<<35)+abs((INT)rand()<<25)+abs((INT)rand());
	int root=rand()%n+1;
	dfs(root);
	ans=1;
	calc(root);
	cout << ans << endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	srand(time(0));
	solve();
	
	return 0;
}