#include <bits/stdc++.h>
 
#pragma GCC optimize("O2", "unroll-loops")
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,m,q,z[MAX][MAX];
bool a,b;
char c;

inline bool mejik(int x){
	if(!x)return false;
	return __builtin_popcount(x-1)&1;
}

ll f(ll r,ll c){
	if(r==0||c==0)return 0;
	ll ret,x,y;
	x = r/n, y = c/m;
//	cout<<x<<' '<<y<<" = "<<(n*m*(x*y>>1))<<endl; 
	ret = (n*m*(x*y>>1)) + (r%n*m*(y>>1)) + (c%m*n*(x>>1));
//	db(ret);
	a = mejik(x+1), b = mejik(y+1);
	ret+= (a^b ? (r%n)*(c%m)-z[r%n][c%m] : z[r%n][c%m]);
//	db((a^b));
//	db(ret);
	if(x&y&1){
		a = mejik(x), b = mejik(y);
		if(a^b)ret+= n*m-z[n][m];
		else ret+= z[n][m];
	}
	if(y&1){
		a = mejik(x+1), b = mejik(y);
//		cout<<">> "<<a<<' '<<b<<' '<<r%n<<endl;
		if(a^b)ret+= r%n*m-z[r%n][m];
		else ret+= z[r%n][m];
	}
//	db(ret);
	if(x&1){
		a = mejik(x), b = mejik(y+1);
		if(a^b)ret+= n*(c%m)-z[n][c%m];
		else ret+= z[n][c%m];
	}
//	cout<<r<<' '<<c<<" = "<<ret<<endl;
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll x1,y1,x2,y2;
    cin>>n>>m>>q;
    rep(i,1,n)rep(j,1,m)cin>>c, z[i][j] = c-'0', z[i][j]+=z[i-1][j]+z[i][j-1]-z[i-1][j-1];
//    db(z[n][m]);
    while(q--){
    	cin>>x1>>y1>>x2>>y2;
//    	f(x2,y1-1);
    	cout<<f(x2,y2)-f(x1-1,y2)-f(x2,y1-1)+f(x1-1,y1-1)<<endl;
	}
	return 0;
}