 #include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 505;
const ll MAX2 = 11;
const int MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll tc,n,x[MAX],y,z,a,b,sz,cnt,tmp,res,ans,dp[MAX][MAX];
string s,t;
pair<ll,pll> p[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>p[i].sf>>p[i].fi>>p[i].ss;
    sort(p+1,p+n+1,greater<pair<ll,pll> >());
    rep(i,0,n)rep(j,0,n)dp[i][j] = -1e18;
    dp[0][0] = 0;
    rep(i,1,n){
		rep(j,1,i){
	    	dp[i][j]=max(dp[i-1][j]+max(0ll,p[i].sf-p[i].fi*p[i].ss),dp[i-1][j-1]+p[i].sf-p[i].fi*(j-1));
		}
	dp[i][0]=dp[i-1][0]+max(0ll,p[i].sf-p[i].fi*p[i].ss);
    }
    rep(i,0,n)ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
	return 0;
}