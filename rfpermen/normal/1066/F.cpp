#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,dp[MAX][2],id,mx,ls;
pll x[MAX],y[MAX][2];

inline bool cmp(pll a,pll b){
	return max(a.fi,a.se) < max(b.fi,b.se);
}

ll f(int nw,bool st){
	if(dp[nw][st]!=-1)return dp[nw][st];
	ll &ret = dp[nw][st], tmp = 0;
	tmp = abs(y[nw][0].fi-y[nw][1].fi) + abs(y[nw][0].se-y[nw][1].se);
	if(nw==n)return ret = tmp;
	ll a = y[nw][st].fi, b = y[nw][st].se;
	return ret = min(	abs(a-y[nw+1][0].fi) + abs(b-y[nw+1][0].se) + f(nw+1,1),
						abs(a-y[nw+1][1].fi) + abs(b-y[nw+1][1].se) + f(nw+1,0))+tmp;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].se;
    sort(x+1,x+1+n,cmp);
    rep(i,1,n){
    	mx = max(x[i].fi,x[i].se);
    	x[i].se = -x[i].se;
    	if(mx!=ls){
    		++id, y[id][0] = y[id][1] = x[i], ls = mx;
		}
		else 
		y[id][0] = min(y[id][0],x[i]),
		y[id][1] = max(y[id][1],x[i]);
	}
	memset(dp,-1,sizeof dp);
	n = id;
	rep(i,1,n)rep(j,0,1)y[i][j].se = -y[i][j].se;
	cout<<f(0,0)<<endl;
    return 0;
}