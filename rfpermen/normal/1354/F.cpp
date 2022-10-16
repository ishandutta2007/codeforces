#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 77+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int tc,n,k,dp[MAX][MAX],tmp;
piii x[MAX];
vector<int> ans;
bool vis[MAX];

int f(int nw,int pos){
	if(pos>k)return -MOD;
	if(nw>n)return (pos==k ? 0 : -MOD);
	if(dp[nw][pos]!=-1)return dp[nw][pos];
	return dp[nw][pos] = max(f(nw+1,pos+1)+x[nw].sf+pos*x[nw].fi, f(nw+1,pos)+x[nw].fi*(k-1));
}

void bt(int nw,int pos){
	if(nw>n)return;
	if(dp[nw][pos]==f(nw+1,pos+1)+x[nw].sf+pos*x[nw].fi)vis[x[nw].ss] = 1, ans.pb(x[nw].ss), bt(nw+1,pos+1);
	else bt(nw+1,pos);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>k;
    	rep(i,1,n)cin>>x[i].sf>>x[i].fi, x[i].ss = i;
    	sort(x+1,x+1+n);
    	memset(dp,-1,sizeof dp);
    	f(1,0);
//    	db(f(1,0));
    	ans.clear();
    	memset(vis,0,sizeof vis);
    	bt(1,0), tmp = ans.back(), ans.pob();
    	rep(i,1,n)if(!vis[i])ans.pb(i), ans.pb(-i);
    	ans.pb(tmp);
    	cout<<ans.size()<<endl;
    	for(auto i:ans)cout<<i<<' '; cout<<endl;
	}
    return 0;
}