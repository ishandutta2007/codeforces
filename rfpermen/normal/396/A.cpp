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

ll n,x,f[20005],ans;
map<int,int> m;

inline ll pw(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b&1)ret = (ret*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = 1;
    rep(i,1,20000)f[i] = (f[i-1]*i)%MOD;
    cin>>n;
    rep(i,1,n){
    	cin>>x;
    	for(int j = 2; j*j<=x; ++j)while(x%j==0)m[j]++, x/=j;
    	if(x!=1)m[x]++;
	}
	ans = 1;
	for(auto i:m)ans = ans * f[i.se+n-1] % MOD * pw(f[i.se],MOD-2) % MOD * pw(f[n-1],MOD-2) % MOD;
	cout<<ans<<endl;
	return 0;
}