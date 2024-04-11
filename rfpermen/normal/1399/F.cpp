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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,n,dp[MAX][MAX<<1],jmp[MAX<<1],id;
pii x[MAX];
vector<int> v;
map<int,int> m;

int f(int nw,int bt){
	if(x[nw].fi>bt)return 0;
	if(dp[nw][bt]!=-1)return dp[nw][bt];
	if(x[nw].se>bt)return dp[nw][bt] = f(nw+1,bt);
	return dp[nw][bt] = max(f(nw+1,bt),f(nw+1,x[nw].se)+f(jmp[x[nw].se],bt)+1);
}

inline bool cmp(pii a,pii b){
	if(a.fi==b.fi)return a.se>b.se;
	return a.fi<b.fi;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	m.clear(), id = 0;
    	rep(i,1,n)cin>>x[i].fi>>x[i].se, m[x[i].fi], m[x[i].se];
    	for(auto &i:m)i.se = ++id;
    	rep(i,1,n)x[i] = {m[x[i].fi], m[x[i].se]}, mems(dp[i],-1);
    	sort(x+1,x+1+n,cmp);
    	v.clear();
    	rep(i,1,n)v.pb(x[i].fi);
    	auto it = v.begin();
    	rep(i,1,id)jmp[i] = upper_bound(all(v),i)-v.begin()+1;
    	x[n+1].fi = MOD;
    	
//    	cout<<"______\n";
//    	rep(i,1,n)cout<<x[i].fi<<' '<<x[i].se<<endl;
//    	rep(i,1,id)cout<<i<<" = "<<jmp[i]<<endl;
    	
    	cout<<f(1,id)<<endl;
	}
    return 0;
}