#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
ll tc,n,x[MAX],sm,cnt[65],ans,a,b;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	mems(cnt,0);
    	sm = 0;
    	rep(i,1,n){
    		cin>>x[i];
    		rep(j,0,59)if(x[i]&(1ll<<j))++cnt[j];
    		sm+= x[i]%MOD;
		}
		sm%= MOD;
    	ans = 0;
    	rep(i,1,n){
    		a = sm, b = 0;
    		rep(j,0,59)if(x[i]&(1ll<<j)){
    			a+= (n-cnt[j])*((1ll<<j)%MOD)%MOD;
    			b+= cnt[j]*((1ll<<j)%MOD)%MOD;
			}
			a%= MOD, b%= MOD;
			ans+= a*b%MOD;
//			cout<<">> "<<a<<' '<<b<<endl;
		}
    	cout<<ans%MOD<<endl;
	}
    return 0;
}