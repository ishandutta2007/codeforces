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
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,dis[MAX][MAX],a,b,c,t[MAX],cs[MAX],nw,st,en;
ll vis[MAX],nwc;
vector<pii> v[MAX];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 
int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>st>>en;
    rep(i,1,m){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	v[b].pb({a,c});
	}
	rep(i,1,n)rep(j,1,n)dis[i][j] = MOD;
	rep(i,1,n){
		dis[i][i] = 0;
		pq.push({0,i});
		while(!pq.empty()){
			nw = pq.top().se, nwc = pq.top().fi, pq.pop();
			if(dis[i][nw]<nwc)continue;
			for(pii j:v[nw])if(nwc+j.se<dis[i][j.fi]){
				dis[i][j.fi] = nwc+j.se;
				pq.push({nwc+j.se,j.fi});
			}
		}
	}
	
	rep(i,1,n)cin>>t[i]>>cs[i], vis[i] = INF;
	vis[st] = 0;
	pq.push({0,st});
	while(!pq.empty()){
		nw = pq.top().se, nwc = pq.top().fi, pq.pop();
		if(vis[nw]<nwc)continue;
		rep(i,1,n)if(nwc+cs[nw]<vis[i] && dis[nw][i]<=t[nw]){
			vis[i] = nwc+cs[nw];
			pq.push({vis[i],i});
		}
	}
	if(vis[en]==INF)vis[en] = -1;
	cout<<vis[en]<<endl;
    return 0;
}