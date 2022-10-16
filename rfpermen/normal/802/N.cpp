#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 312;

#define MCMF MincostMaxflow
#define flow_t int
#define cost_t ll
const flow_t foo = (flow_t) 1e9;
const cost_t coo = (cost_t) 1e18;
namespace MincostMaxflow {
	const int maxv = 1e5 + 5;
	const int maxe = 1e6 + 5;
	int n, s, t, E;
	int adj[maxe], nxt[maxe], lst[maxv], frm[maxv], vis[maxv];
	flow_t cap[maxe], flw[maxe], totalFlow;
	cost_t cst[maxe], dst[maxv], totalCost;

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		fill_n(lst, n, -1), E = 0;
	}
	void add(int u, int v, flow_t ca, cost_t co) {
		adj[E] = v, cap[E] = ca, flw[E] = 0, cst[E] = +co;
		nxt[E] = lst[u], lst[u] = E++;
		adj[E] = u, cap[E] =  0, flw[E] = 0, cst[E] = -co;
		nxt[E] = lst[v], lst[v] = E++;
	}
	int spfa() {
		fill_n(dst, n, coo), dst[s] = 0;
		queue<int> que; que.push(s);
		while (que.size()) {
			int u = que.front(); que.pop();
			for (int e = lst[u]; e != -1; e = nxt[e]) if (flw[e] < cap[e]) {
				int v = adj[e];
				if (dst[v] > dst[u] + cst[e]) {
					dst[v] = dst[u] + cst[e];
					frm[v] = e;
					if (!vis[v]) {
						vis[v] = 1;
						que.push(v);
			}	}	}
			vis[u] = 0;
		}
		return dst[t] < coo;
	}
	cost_t mincost() {
		totalCost = 0, totalFlow = 0;
		while (1) {
			if (!spfa()) break;
			flow_t mn = foo;
			for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) {
				mn = min(mn, cap[e] - flw[e]);
			}
			for (int v = t, e = frm[v]; v != s; v = adj[e ^ 1], e = frm[v]) {
				flw[e] += mn;
				flw[e ^ 1] -= mn;
			}
			totalFlow += mn;
			totalCost += mn * dst[t];
		}
		return totalCost;
}	}

int n,k,x[MAX],y[MAX];

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>y[i];
	MCMF::init(n+3, 0, n+2);
	MCMF::add(0, 1, k, 0);
	rep(i,1,n){
		MCMF::add(1, i+1, 1, x[i]);
		MCMF::add(i+1, n+2, 1, y[i]);
		if(i>1)MCMF::add(i, i+1, MOD, 0);
	}
	cout<<MCMF::mincost()<<endl;
    return 0;
}