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
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const int MAX = 3e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,a,b,c,dp[MAX],ans,nw[MAX],cs[MAX],pg[MAX],mx[MAX];
vector<pii> v[MAX];
vector<int> res[MAX];

int f(int pos){
	if(dp[pos]!=-1)return dp[pos];
	int i = nw[pos];
	int it = lower_bound(all(v[i]),mp(cs[pos]+1,0)) - v[i].begin();
	while(it<pg[i]){
		--pg[i];
		res[i][pg[i]] = max(f(v[i][pg[i]].se)+1,mx[i]);
		mx[i] = max(mx[i],res[i][pg[i]]);
	}
	return dp[pos] = it==v[i].size() ? 0 : res[i][it];
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>nw[i]>>cs[i];
    	v[a].pb({cs[i],i});
	}
	rep(i,1,n)if(v[i].size())sort(all(v[i])), pg[i] = v[i].size(), res[i].resize(pg[i]);
	mems(dp,-1);
	rep(i,1,m)ans = max(ans,f(i));
	cout<<ans+1<<endl;
    return 0;
}