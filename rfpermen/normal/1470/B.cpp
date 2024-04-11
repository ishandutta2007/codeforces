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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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

ll tc,n,q,x,a[MAX],b[MAX],y,z;
pll pre[MAX];
bool st;
map<pll,int> cnt;

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    a[0] = b[0] = 1;
    rep(i,1,1000000)a[i] = a[i-1]*2010405347, b[i] = b[i-1]*13;
    
    rep(i,1,1000000){
    	x = i;
    	y = z = 0;
		for(int j = 2; j*j<=x; ++j)if(x%j==0){
			st = 0;
			while(x%j==0)x/=j, st^=1;
			if(st)y+= a[j], z^= b[j];
		}
		if(x!=1)y+= a[x], z^= b[x];
		pre[i] = {y,z};
	}
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	cnt.clear();
    	rep(i,1,n){
    		cin>>x;
			++cnt[pre[x]];
		}
		y = z = 0;
		for(auto i:cnt){
			y = max(y,(ll)i.se);
			if(i.se%2==0)z+= i.se;
		}
		if(cnt[{0,0}]&1)z+= cnt[{0,0}];
		z = max(y,z);
		cin>>q;
		while(q--){
			cin>>x;
			if(x)cout<<z<<endl;
			else cout<<y<<endl;
		}
	}
    return 0;
}