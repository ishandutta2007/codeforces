#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const ll inf=1ll<<50;

namespace mincost{

const int V=1234567,E=1234567;
int vis[V],ti,g[V],et;
ll r[V];
int vtot,s,t;
ll infc=1e18,inff=1e18;
struct edge{ int v,ne;ll f,c;} e[E*2];
void init(int _s,int _t,int _n){
	s=_s;
	t=_t;
	vtot=_n;
	rep(i,0,vtot) g[i]=-1;
	et=0;
}

void add(int u,int v,ll f,ll c){
	e[et]={v,g[u],f,c}; g[u]=et++;
	e[et]={u,g[v],0,-c}; g[v]=et++;
}
int d[V],cu[V];

void spfa(){
	static int qu[V],in[V];
	int p=0,q=0;
	rep(i,0,vtot) r[i]=infc,cu[i]=g[i];
	r[s]=0;
	qu[q++]=s,in[s]=1;
	while(p!=q){
		int u=qu[p++]; if(p==V) p=0;
		in[u]=0;
		for(int i=g[u];~i;i=e[i].ne) {
			int v=e[i].v;
			if (e[i].f&&r[v]>r[u]+e[i].c) {
				r[v]=r[u]+e[i].c;
				if(!in[v]) {
					in[v]=1;
					qu[q++]=v; if(q==V)q=0;
				}
			}
		}
	}
}
void dij(){
	static pair<ll,int> qu[E*2];
	int tq=0;
	static ll d[V];
	rep(i,0,vtot) d[i]=infc,cu[i]=g[i];
	d[s]=0;
	qu[tq++]=mp(0,s); push_heap(qu,qu+tq);
	while(tq) {
		auto x=qu[0]; pop_heap(qu,qu+tq); --tq;
		int u=x.second;
		if (d[u]!=-x.first) continue;
		for(int i=g[u];~i;i=e[i].ne) {
			ll w=d[u]+e[i].c+r[u]-r[e[i].v];
			if(e[i].f&&w<d[e[i].v]) {
				d[e[i].v]=w;
				qu[tq++]=mp(-d[e[i].v],e[i].v);
				push_heap(qu,qu+tq);
			}
		}
	}
	rep(i,0,vtot) r[i]+=d[i];
}
ll aug(int u,ll m){
	if (u==t) return m;
	ll su=0,f;
	vis[u]=ti;
	for(int i=cu[u];~i;cu[u]=i=e[i].ne)
		if (e[i].f&&vis[e[i].v]!=ti&&r[u]+e[i].c==r[e[i].v]) {
			f=aug(e[i].v,min(m,e[i].f));
			e[i].f-=f; e[i^1].f+=f;
			m-=f; su+=f;
			if(!m)break;
		}
	if(su) vis[u]=-1;
	return su;
}
ll mcmf(){
	rep(i,0,vtot) r[i]=0;
	spfa();	//call if negative edges exist
	ll co=0,flo=0,f;
	while (ti++,dij(),f=aug(s,inff)) {
    if (r[t]>0) break;
		flo+=f;
		co+=r[t]*f;
	}
	return co;
}

}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  mincost::init(n * n, n * n + 1, n * n + 2);
  int src = n * n, snk = n * n + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int v = i * n + j;
      if (j + 1 < n && i > 0 && i < n - 1 && a[i][j] != -1 && a[i][j + 1] != -1) {
        mincost::add(v, v + 1, 1, 0);
        mincost::add(v + 1, v, 1, 0);
      }
      if (i + 1 < n && j > 0 && j < n - 1 && a[i][j] != -1 && a[i + 1][j] != -1) {
        mincost::add(v, v + n, 1, 0);
        mincost::add(v + n, v, 1, 0);
      }
      if (a[i][j] > 0) {
        mincost::add(src, v, 1, a[i][j]);
        mincost::add(v, snk, 1, -a[i][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    ans += abs(a[0][i] - a[0][i + 1]);
    ans += abs(a[n - 1][i] - a[n - 1][i + 1]);
    ans += abs(a[i][0] - a[i + 1][0]);
    ans += abs(a[i][n - 1] - a[i + 1][n - 1]);
  }
  cout << ans - mincost::mcmf() << "\n";
  return 0;
}