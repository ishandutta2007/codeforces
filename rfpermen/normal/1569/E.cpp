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
const int MAX = 4e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll n,n2,k,a,A,B,b,h,en,val,ans[50];
vector<int> v,u;
vector<ll> p;
map<int,int> w,x,y,z;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>k>>a>>h;
	A = a;
	B = a*a%MOD;
	
	n = 1<<k;
	n2 = n/2;
	en = (1<<n2-1)-1;
	val = 3;
	rep(i,3,k)val = (val-1)*2+1;
	n2/= 2;
	while(n2){
		rep(i,1,n2)p.pb(pw(a,val)), u.pb(val);
		n2/= 2;
		val = (val-1)/2+1;
	}
	
	n2 = n/2;
	rep(mask,0,en){
		v.clear();
		rep(i,1,n2)v.pb(i);
		val = 0;
		For(i,0,n2-1){
			a = v[i*2], b = v[i*2+1];
			if(mask&(1<<i)){
				v.pb(b);
				val+= a*p[i]%MOD;
			}
			else {
				v.pb(a);
				val+= b*p[i]%MOD;
			}
		}
		w[(val+A*v.back())%MOD] = mask;
		x[(val+B*v.back())%MOD] = mask;
		
		v.clear();
		rep(i,n2+1,n)v.pb(i);
		val = 0;
		For(i,0,n2-1){
			a = v[i*2], b = v[i*2+1];
			if(mask&(1<<i)){
				v.pb(b);
				val+= a*p[i]%MOD;
			}
			else {
				v.pb(a);
				val+= b*p[i]%MOD;
			}
		}
		y[(val+A*v.back())%MOD] = mask;
		z[(val+B*v.back())%MOD] = mask;
	}
	int mask;
	for(auto i:w){
		val = (h-i.fi+MOD)%MOD;
		if(z.count(val)){
			v.clear();
			mask = i.se;
			rep(i,1,n2)v.pb(i);
			For(i,0,n2-1){
				a = v[i*2], b = v[i*2+1];
				if(mask&(1<<i)){
					v.pb(b);
					ans[a] = u[i];
				}
				else {
					v.pb(a);
					ans[b] = u[i];
				}
			}
			ans[v.back()] = 1;
			
			v.clear();
			mask = z[val];
			rep(i,n2+1,n)v.pb(i);
			For(i,0,n2-1){
				a = v[i*2], b = v[i*2+1];
				if(mask&(1<<i)){
					v.pb(b);
					ans[a] = u[i];
				}
				else {
					v.pb(a);
					ans[b] = u[i];
				}
			}
			ans[v.back()] = 2;
			rep(i,1,n)cout<<ans[i]<<" "; cout<<endl;
			return 0;
		}
	}
	for(auto i:x){
		val = (h-i.fi+MOD)%MOD;
		if(y.count(val)){
			v.clear();
			mask = i.se;
			rep(i,1,n2)v.pb(i);
			For(i,0,n2-1){
				a = v[i*2], b = v[i*2+1];
				if(mask&(1<<i)){
					v.pb(b);
					ans[a] = u[i];
				}
				else {
					v.pb(a);
					ans[b] = u[i];
				}
			}
			ans[v.back()] = 2;
			
			v.clear();
			mask = y[val];
			rep(i,n2+1,n)v.pb(i);
			For(i,0,n2-1){
				a = v[i*2], b = v[i*2+1];
				if(mask&(1<<i)){
					v.pb(b);
					ans[a] = u[i];
				}
				else {
					v.pb(a);
					ans[b] = u[i];
				}
			}
			ans[v.back()] = 1;
			rep(i,1,n)cout<<ans[i]<<" "; cout<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}