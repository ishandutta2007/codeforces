#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e4+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 400;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll n,le,ri,en,k;
arll(16) a,b;
ll x[16][16],ret[16][16],tmp[16][16];

inline void matpow(ll y,int n){
	mems(ret,0);
	rep(i,0,n)ret[i][i] = 1;
	mems(x,0);
	rep(i,0,n)rep(j,-1,1)if(i+j>=0 && i+j<=n)x[i][i+j] = 1;
//	rep(i,0,n){
//		rep(j,0,n)cout<<x[i][j]; cout<<endl;
//	}
	while(y){
		if(y&1){
			mems(tmp,0);
			rep(i,0,n)rep(k,0,n)if(ret[i][k])rep(j,0,n)tmp[i][j]+= ret[i][k]*x[k][j]%MOD;
			rep(i,0,n)rep(j,0,n)ret[i][j] = tmp[i][j]%MOD;
		}
		mems(tmp,0);
		rep(i,0,n)rep(k,0,n)if(x[i][k])rep(j,0,n)tmp[i][j]+= x[i][k]*x[k][j]%MOD;
		rep(i,0,n)rep(j,0,n)x[i][j] = tmp[i][j]%MOD;
		y>>=1;
	}
	mems(b,0);
	rep(i,0,n)rep(j,0,n)b[j]+= a[i]*ret[i][j]%MOD;
	rep(i,0,15)a[i] = b[i]%MOD;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>en;
	a[0] = 1;
	rep(i,1,n){
		cin>>le>>ri>>k;
		ri = min(ri,en);
		if(!k){
			rep(j,1,15)a[j] = 0;
			continue;
		}
		matpow(ri-le,k);
	}
	cout<<a[0]<<endl;
	return 0;
}