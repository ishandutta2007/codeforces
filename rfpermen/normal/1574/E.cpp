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
const int MAX = 1e6+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll ans;
int n,m,q,x,y,val,r[2][MAX],c[2][MAX],ver,hor,a,b,k,K;
map<pii,bool> z;

inline ll f(){
	if(ver && hor)return 0;
	if(!a && !b)return 2*(pw(2,n-1)+pw(2,m-1)-1)%MOD;
	ll ret = 0;
	if(!ver)ret+= pw(2,n-a);
	if(!hor)ret+= pw(2,m-b);
	if(!(k && K))ret--;
	return ret%MOD;
}

void del(int x,int y){
	if(!z.count({x,y}))return;
	int v = z[{x,y}];
	k-= ((x+y)&1)^v;
	K-= ((x+y)&1)^v^1;
	z.erase({x,y});
	
	ver-= !!r[0][x] && !!r[1][x];
	hor-= !!c[0][y] && !!c[1][y];
	a-= !!r[0][x] || !!r[1][x];
	b-= !!c[0][y] || !!c[1][y];
	
	--r[v^(y&1)][x];
	--c[v^(x&1)][y];
	
	ver+= !!r[0][x] && !!r[1][x];
	hor+= !!c[0][y] && !!c[1][y];
	a+= !!r[0][x] || !!r[1][x];
	b+= !!c[0][y] || !!c[1][y];
}

void one(int x,int y){
	int v = 1;
	z[{x,y}] = v;
	k+= ((x+y)&1)^v;
	K+= ((x+y)&1)^v^1;
	
	ver-= !!r[0][x] && !!r[1][x];
	hor-= !!c[0][y] && !!c[1][y];
	a-= !!r[0][x] || !!r[1][x];
	b-= !!c[0][y] || !!c[1][y];
	
	++r[v^(y&1)][x];
	++c[v^(x&1)][y];
//	out(r[0][x],r[1][x]);
	
	ver+= !!r[0][x] && !!r[1][x];
	hor+= !!c[0][y] && !!c[1][y];
	a+= !!r[0][x] || !!r[1][x];
	b+= !!c[0][y] || !!c[1][y];
}

void zero(int x,int y){
	int v = 0;
	z[{x,y}] = v;
	k+= ((x+y)&1)^v;
	K+= ((x+y)&1)^v^1;
	
	ver-= !!r[0][x] && !!r[1][x];
	hor-= !!c[0][y] && !!c[1][y];
	a-= !!r[0][x] || !!r[1][x];
	b-= !!c[0][y] || !!c[1][y];
	
	++r[v^(y&1)][x];
	++c[v^(x&1)][y];
	
	ver+= !!r[0][x] && !!r[1][x];
	hor+= !!c[0][y] && !!c[1][y];
	a+= !!r[0][x] || !!r[1][x];
	b+= !!c[0][y] || !!c[1][y];
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>q;
	while(q--){
		cin>>x>>y>>val;
		del(x,y);
		if(val==0)zero(x,y);
		else if(val==1)one(x,y);
		cout<<f()<<endl;
	}
	return 0;
}