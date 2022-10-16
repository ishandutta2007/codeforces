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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,z,k,x[MAX],bit[2][MAX],cnt;
ll ans;

inline void upd(int j,int i){
	i+=z;
	for(;i<m;i+=i&-i)--bit[j][i]; return;
}

int ret;
inline int que(int j,int i){
	i+=z-1, ret = 0;
	for(;i>0;i-=i&-i)ret+= bit[j][i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    ans = (ll)n*(n+1)>>1;
    m = 1<<18, z = 1<<17;
    //high
    upd(0,0), upd(1,0);
    rep(i,1,n){
    	if(x[i]>k)++cnt;
    	if(i&1){
    		ans+= que(1,cnt);
    		upd(0,cnt-1), upd(1,cnt);
		}
    	else {
    		--cnt;
    		ans+= que(0,cnt);
    		upd(0,cnt), upd(1,cnt);
		}
	}
	//low
	memset(bit,0,sizeof bit);
    upd(0,0), upd(1,0);
    cnt = 1;
    rep(i,1,n){
    	if(x[i]<k)++cnt;
    	if(i&1){
    		--cnt;
    		ans+= que(1,cnt);
    		upd(0,cnt), upd(1,cnt-1);
		}
    	else {
    		ans+= que(0,cnt);
    		upd(0,cnt-1), upd(1,cnt-1);
		}
	}
	cout<<ans<<endl;
    return 0;
}