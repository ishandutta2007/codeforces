#include<bits/stdc++.h>
 
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
//#define lc (id<<1)
//#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
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
const int MAX = 1e6+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,x[MAX],p[MAX],d[MAX],z,cnt,op,a,b;
ll bit[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void upd(int i,int val){
	for(; i<=n; i+=i&-i)bit[i]+= val;
	return;
}

ll ret;
inline ll que(int i){
	ret = 0;
	for(; i>0; i^=i&-i)ret+= bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	For(i,2,MAX)d[i] = 1;
	For(i,2,MAX)if(d[i]==1){
		rip(j,i,1000000,i){
			cnt = 2, z = j/i;
			while(z%i==0)++cnt, z/= i;
			d[j]*= cnt;
		}
	}
	cin>>n>>m;
	rep(i,1,n){
		cin>>x[i];
		if(x[i]<=2)p[i] = i+1;
		else p[i] = i;
		upd(i,x[i]);
	}
	p[n+1] = n+1;
	while(m--){
		cin>>op>>a>>b;
		if(op==1){
			a = par(a);
			while(a<=b){
				upd(a,d[x[a]]-x[a]);
				x[a] = d[x[a]];
				if(x[a]<=2)p[a] = par(a+1), a = p[a];
				else a = par(a+1);
			}
		}
		else {
			cout<<que(b)-que(a-1)<<endl;
		}
	}
	return 0;
}