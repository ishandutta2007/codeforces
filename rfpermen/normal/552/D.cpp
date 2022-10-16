#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,ans,a,b,da,db,fpb;
pii x[2005];
bool vis[205][205];
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].se, vis[x[i].fi+100][x[i].se+100] = 1;
    ans = n*(n-1)*(n-2)/6;
    sort(x+1,x+1+n);
    rep(i,1,n)rep(j,i+1,n){
    	da = x[j].fi-x[i].fi, db = x[j].se-x[i].se;
    	fpb = abs(__gcd(da,db));
    	da/=fpb, db/=fpb;
    	a = x[j].fi+100+da, b = x[j].se+100+db;
    	while(a<=200&&b<=200&&b>=0){
    		if(vis[a][b])ans--;
    		a+=da, b+=db;
		}
	}
	cout<<ans<<endl;
	return 0;
}