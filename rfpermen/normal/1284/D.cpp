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
const int MAX = 5e5+5;
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

int n,k,id,bit[MAX],res[MAX];
ari(4) x[MAX];
map<int,int> hs;

inline void upd(int i){
	for(; i<=k; i+=i&-i)++bit[i];
	return;
}
int ret;
inline int que(int i){
	ret = 0;
	for(; i>0; i-=i&-i)ret+= bit[i];
	return ret;
}

vector<ari(4)> v;

bool solve(){
	v.clear();
	rep(i,1,n){
		v.pb({x[i][1],0,x[i][2],x[i][3]});
		v.pb({x[i][0],-i,x[i][2],x[i][3]});
	}
	sort(all(v));
	for(auto &i:v)i[1]*= -1;
	mems(bit,0);
	
	for(auto i:v){
		if(i[1]){
			res[i[1]] = que(i[2]-1);
		}
		else {
			upd(i[3]);
		}
	}
	mems(bit,0);
	
	id = 0;
	for(auto i:v){
		if(i[1]){
			if(id!=res[i[1]] + que(k-i[3]))return false;
		}
		else {
			++id;
			upd(k-i[2]+1);
		}
	}
	
	
	v.clear();
	rep(i,1,n){
		v.pb({x[i][1],i,x[i][2],x[i][3]});
		v.pb({x[i][0],0,x[i][2],x[i][3]});
	}
	sort(all(v));
	reverse(all(v));
	mems(bit,0);
	
	for(auto i:v){
		if(i[1]){
			res[i[1]] = que(i[2]-1);
		}
		else {
			upd(i[3]);
		}
	}
	mems(bit,0);
	
	id = 0;
	for(auto i:v){
		if(i[1]){
			if(id!=res[i[1]] + que(k-i[3]))return false;
		}
		else {
			++id;
			upd(k-i[2]+1);
		}
	}
	return true;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n; k = n<<1;
	rep(i,1,n)rep(j,0,3)cin>>x[i][j];
	rep(i,1,n)rep(j,0,1)hs[x[i][j]];
	for(auto i:hs)hs[i.fi] = ++id;
	rep(i,1,n)rep(j,0,1)x[i][j] = hs[x[i][j]];
	hs.clear(), id = 0;
	rep(i,1,n)rep(j,2,3)hs[x[i][j]];
	for(auto i:hs)hs[i.fi] = ++id;
	rep(i,1,n)rep(j,2,3)x[i][j] = hs[x[i][j]];
	
//	rep(i,1,n){
//		rep(j,0,3)cout<<x[i][j]<<" ";
//		cout<<endl;
//	}
	
	if(!solve())return cout<<"NO\n",0;
	rep(i,1,n)swap(x[i][0], x[i][2]), swap(x[i][1], x[i][3]);
	if(!solve())return cout<<"NO\n",0;
	cout<<"YES\n";
	return 0;
}