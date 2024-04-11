#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
 
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
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,x,y,ans;
vector<int> fc;

inline ll f(int y){
	--y;
	ll x = 2, ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

void bf(int pos,int nw,bool st){
	if(pos==fc.size()){
		if(st)ans+= f(n/nw);
		else ans-= f(n/nw);
		return;
	}
	bf(pos+1,nw,st);
	bf(pos+1,nw*fc[pos],st^1);
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    if(y%x!=0)return cout<<"0\n",0;
    n = y/x;
    for(int i = 2; i*i<=n; ++i)if(n%i==0){
    	fc.pb(i);
    	while(n%i==0)n/= i;
	}
	if(n!=1)fc.pb(n);
	n = y/x;
	bf(0,1,1);
	ans%= MOD;
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
    return 0;
}