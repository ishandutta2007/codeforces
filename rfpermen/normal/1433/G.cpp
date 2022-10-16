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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,k,ans,vis[MAX][MAX],a,b,c,nw,nc,x[MAX],y[MAX],res;
vector<pii> v[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,m){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	v[b].pb({a,c});
	}
	rep(o,1,n){
		rep(i,1,n)vis[o][i] = MOD;
		vis[o][o] = 0;
		pq.push({0,o});
		while(!pq.empty()){
			nw = pq.top().se, c = pq.top().fi; pq.pop();
			if(vis[o][nw]<c)continue;
			for(pii i:v[nw]){
				nc = c+i.se;
				if(vis[o][i.fi]>nc){
					vis[o][i.fi] = nc;
					pq.push({nc,i.fi});
				}
			}
		}
	}
	rep(i,1,k)cin>>x[i]>>y[i], ans+= vis[x[i]][y[i]];
	rep(i,1,n){
		for(pii j:v[i]){
			res = 0;
			rep(o,1,k)res+= min(vis[x[o]][y[o]], min(vis[x[o]][i]+vis[j.fi][y[o]],
													 vis[x[o]][j.fi]+vis[i][y[o]]));
			ans = min(ans,res);
		}
	}
	cout<<ans<<endl;
    return 0;
}