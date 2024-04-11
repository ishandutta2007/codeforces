#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

#define MCMF MincostMaxflow
#define flow_t int
#define cost_t int
const flow_t foo = (flow_t) 1e9;
const cost_t coo = (cost_t) 1e9;
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
	pii mincost() {
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
		return {totalCost,totalFlow};
}	}

int n,cnt[26];
string s;

inline void hit(){
	mems(cnt,0);
	for(char c:s)cnt[c-'a']++;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>n;
    int len = s.size();
    int tt = (n+1)*27;
    MCMF::init(tt+1, 0, tt);
    hit();
    rep(i,0,25)if(cnt[i])MCMF::add(0, i+1, cnt[i], 0);
    int k;
    rep(i,1,n){
    	cin>>s>>k;
    	hit();
    	rep(j,0,25)if(cnt[j]){
    		MCMF::add(j+1, i*27+j, cnt[j], 0);
    		MCMF::add(i*27+j, i*27+26, cnt[j], 0);
		}
		MCMF::add(i*27+26, tt, k, i);
	}
	pii res = MCMF::mincost();
	if(res.se!=len)cout<<"-1\n";
	else cout<<res.fi<<endl;
    return 0;
}