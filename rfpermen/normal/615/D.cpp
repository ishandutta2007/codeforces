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
const int MAX = 5e5+10;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
ll n,x,cnt[MAX],y[MAX],pr[MAX],ans,mul;
vector<int> v;

inline ll pw(ll x,ll y,ll z){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%z;
		x = x*x%z;
		y>>=1;
	}
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x, ++cnt[x];
    ans = mul = 1;
    rep(i,2,200000)y[cnt[i]+1]++;
    rep(i,2,200001)if(y[i])v.pb(i);
    rep(i,2,200001){
    	if(y[i]){
    		mul = 1;
    		for(auto j:v){
    			if(i==j)mul = mul * pw(j,y[j]-1,MOD2) % MOD2;
    			else mul = mul * pw(j,y[j],MOD2) % MOD2;
			}
			pr[i] = mul;
		}
	}
//	db(y[3]);
	rep(i,2,200000){
    	if(!cnt[i])continue;
//    	db(pr[cnt[i]+1]);
//    	db(cnt[i]+1);
//    	db(pr[cnt[i]+1] % MOD2 * (cnt[i]*(cnt[i]+1)/2 % MOD2) % MOD2);
    	ans = ans * pw(i,pr[cnt[i]+1] % MOD2 * (cnt[i]*(cnt[i]+1)/2 % MOD2) % MOD2, MOD) % MOD;
	}
	cout<<ans<<endl;
    return 0;
}