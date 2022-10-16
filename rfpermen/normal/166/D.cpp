#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
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
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,m,a,b,dp[MAX][4];
pll x[MAX];
vector<int> z[MAX];
unordered_map<int,int> hs[MAX],as;
unordered_map<int,vector<pii>> cs;
vector<pii> ans;

ll f(int nw,int st){
	if(nw>n)return 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	int k = 0;
	ll ret = f(nw+1,0);
	for(auto i:z[nw]){
		++k;
		if(k==st)continue;
		if(!hs[nw+1].count(i))ret = max(ret,f(nw+1,0)+x[nw].se);
		else ret = max(ret,f(nw+1,hs[nw+1][i])+x[nw].se);
	}
	return dp[nw][st] = ret;
}

void bt(int nw,int st){
	if(nw>n)return;
	int k = 0;
	if(dp[nw][st]==f(nw+1,0))bt(nw+1,0);
	else {
		for(auto i:z[nw]){
			++k;
			if(k==st)continue;
			if(!hs[nw+1].count(i)){
				if(dp[nw][st]==f(nw+1,0)+x[nw].se){
					ans.pb({as[x[nw].fi],i});
					bt(nw+1,0);
					break;
				}
			}
			else if(dp[nw][st]==f(nw+1,hs[nw+1][i])+x[nw].se){
				ans.pb({as[x[nw].fi],i});
				bt(nw+1,hs[nw+1][i]);
				break;
			}
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].se>>x[i].fi, as[x[i].fi] = i;
    sort(x+1,x+1+n);
    cin>>m;
    rep(i,1,m){
    	cin>>a>>b;
    	cs[b].pb({a,i});
	}
	rep(i,1,n){
		if(cs.count(x[i].fi)){
			for(auto k:cs[x[i].fi]){
				if(k.fi>=x[i].se)z[i].pb(k.se);
			}
		}
		if(cs.count(x[i].fi-1)){
			for(auto k:cs[x[i].fi-1]){
				if(k.fi>=x[i].se)z[i].pb(k.se);
			}
		}
		while(z[i].size()>3)z[i].pob();
		a = 0;
		for(auto k:z[i])hs[i][k] = ++a;
	}
	memset(dp,-1,sizeof dp);
	cout<<f(1,0)<<endl;
	bt(1,0);
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.se<<' '<<i.fi<<endl;
    return 0;
}