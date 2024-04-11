#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll x[7],y[7],ttl,z;
vector<ll> a;
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,6)cin>>x[i]>>y[i];
    rep(i,1,2){
    	x[1+i*2] = max(min(x[1+i*2],x[2]),x[1]), x[2+i*2] = min(max(x[2+i*2],x[1]),x[2]);
    	y[1+i*2] = max(min(y[1+i*2],y[2]),y[1]), y[2+i*2] = min(max(y[2+i*2],y[1]),y[2]);
	}
	ttl = (x[4]-x[3])*(y[4]-y[3]) + (x[6]-x[5])*(y[6]-y[5]) - (x[2]-x[1])*(y[2]-y[1]);
	if(ttl<0)cout<<"YES\n";
	else {
		rep(i,3,6)a.pb(x[i]);
		sort(all(a));
		z = a[2]-a[1];
		a.clear();
		rep(i,3,6)a.pb(y[i]);
		sort(all(a));
		z*= a[2]-a[1];
		if(ttl-z<0)cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}