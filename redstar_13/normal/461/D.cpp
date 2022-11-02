#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
using namespace std;

typedef long long INT;
typedef vector<int> VI;

int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100011
int N, k;

struct pro{
	public:
		int root[NN];
		int cnt[NN];
		VI adj[NN];
		int n;
		int head[NN], nxt[NN<<1], to[NN<<1];
		int col[NN];
		int E;
		int find_root(int u) { return root[u] == u ? u : root[u] = find_root(root[u]);}
		inline void merge(int u, int v) {
			u = find_root(u);
			v = find_root(v);
			if(u == v) return ;
			if(cnt[u] > cnt[v]) swap(u, v);
			root[u] = v;
			cnt[v] += cnt[u];
		}
		
		void insert(int u, int v, char c) {
			c=c=='o';
			int x=u+v-1, y=u-v+1;
			if(x > N) x = 2*N - x;
			if(y < 1) y = 2 - y;
			v = x+1>>1;
			u = y+1 >> 1;
			u--;
			if(c) {
				adj[u].pb(v);
			}
			else {
				merge(u, v);
			}
		}
		
		
		void init() {
			for(int i=0; i<=n; i++) root[i] = i, cnt[i] = 1;
			memset(head, -1, sizeof head);
			memset(col, -1, sizeof col);
		}
		
		void add(int u, int v) {
			nxt[E] = head[u]; to[E] = v; head[u] = E++;
			nxt[E] = head[v]; to[E] = u; head[v] = E++;
		}
		
		int dfs(int u, int c=0) {
			col[u] = c;
			for(int e = head[u]; ~e; e=nxt[e]) {
				int v = to[e];
				if(col[v]!=-1 and c==col[v]) return 0;
				if(col[v]==-1 and dfs(v, c^1)==0) return 0;
			}
			return 1;
		}
		
		int solve() {
			for(int i=0; i<=n; i++) {
				int v = find_root(i);
				for(int u : adj[i]) {
					u=find_root(u);
					if(u == v) return 0;
					add(u, v);
				}
			}
			int c=0;
			for(int i=0; i<=n; i++) if(root[i]==i and col[i] == -1) {
				if(dfs(i)==0) return 0;
				c++;
			}
			c--;
			return power(2, c, mod);
		}
} a, b;

int solve() {
	int n; 
	cin >> n >> k;
	N = n;
	a.n = n+1>>1;
	b.n = n>>1;
	a.init();
	b.init();
	for(int i=0; i<k; i++) {
		int u, v; char c;
		scanf(" %d %d %c ", &u, &v, &c);
		if(u+v&1) b.insert(u, v, c);
		if((u+v)%2==0) a.insert(u, v, c);
	}
	cout << (INT)a.solve() * b.solve()% mod << endl;
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}