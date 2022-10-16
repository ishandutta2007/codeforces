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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,m,k,X,dp[MAX][11][3];
ll ans,a,b,c;
vi v[MAX],tmp[MAX];

void norm(int nw,int par){
	for(int i:v[nw])if(i!=par){
		tmp[nw].pb(i);
		norm(i,nw);
	}
	return;
}

//0 <k, 1 =k, 2 >k 
ll f(int nw,int rem,int st){
	if(rem<0)return 0;
	if(v[nw].empty())return rem==0;
	if(dp[nw][rem][st]!=-1)return dp[nw][rem][st];
	vector<ll> z(rem+1,0), nx(rem+1);
	z[0] = 1;
	if(st==0){
		for(int i:v[nw]){
			memsv(nx,0);
			rep(j,0,rem)if(z[j]){
				rep(k,0,rem-j){
					nx[j+k]+= z[j]*((f(i,k,0)*a + f(i,k-1,1) + f(i,k,2)*c)%MOD)%MOD;
				}
			}
			rep(j,0,rem)z[j] = nx[j]%MOD;
		}
	}
	else if(st==1){
		for(int i:v[nw]){
			memsv(nx,0);
			rep(j,0,rem)if(z[j]){
				rep(k,0,rem-j){
					nx[j+k]+= z[j]*(f(i,k,0)*a%MOD)%MOD;
				}
			}
			rep(j,0,rem)z[j] = nx[j]%MOD;
		}
	}
	else {
		for(int i:v[nw]){
			memsv(nx,0);
			rep(j,0,rem)if(z[j]){
				rep(k,0,rem-j){
					nx[j+k]+= z[j]*((f(i,k,0)*a + f(i,k,2)*c)%MOD)%MOD;
				}
			}
			rep(j,0,rem)z[j] = nx[j]%MOD;
		}
	}
	return dp[nw][rem][st] = z[rem];
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cin>>k>>X;
	norm(1,0);
	rep(i,1,n)v[i] = tmp[i];
	mems(dp,-1);
	a = k-1, b = 1, c = m-k;
	rep(i,0,X)ans+= (f(1,i,0)*a + f(1,i-1,1) + f(1,i,2)*c)%MOD;
	cout<<ans%MOD<<endl;
	return 0;
}