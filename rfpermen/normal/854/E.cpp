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
const int MAX = 3e5+5;
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

ll n,m,q,c[MAX],bit[MAX],ans[MAX],a,b,x,y,res;
vector<arll(3)> v[MAX],u[MAX];

inline void upd(int i){
	for(; i<=n; i+=i&-i)++bit[i];
	return;
}

ll ret;
inline ll que(int i){
	ret = 0;
	for(; i>0; i-=i&-i)ret+= bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,1,n)cin>>c[i];
	rep(i,1,q){
		cin>>a>>x>>b>>y;
		ans[i] = n*(n-1) - (a-1)*(a-2) - (x-1)*(x-2) - (n-b)*(n-b-1) - (n-y)*(n-y-1);
		if(a>1){
			if(x>1)v[a-1].pb({1,x-1,i});
			if(y<n)v[a-1].pb({y+1,n,i});
		}
		if(b<n){
			if(x>1)u[b+1].pb({1,x-1,i});
			if(y<n)u[b+1].pb({y+1,n,i});
		}
	}
	rep(i,1,n){
		upd(c[i]);
		for(arll(3) &j:v[i]){
			res = que(j[1]) - que(j[0]-1);
			ans[j[2]]+= res*(res-1);
		}
	}
	
	mems(bit,0);
	rap(i,n,1){
		upd(c[i]);
		for(arll(3) &j:u[i]){
			res = que(j[1]) - que(j[0]-1);
			ans[j[2]]+= res*(res-1);
		}
	}
	rep(i,1,q)cout<<(ans[i]>>1)<<endl;
	return 0;
}