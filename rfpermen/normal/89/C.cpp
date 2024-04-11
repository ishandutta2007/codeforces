#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
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
const int MAX = 5e3+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n,m,nw,mx,cnt,a,b,na,nb;
short int lsr[MAX][MAX],nxr[MAX][MAX],lsc[MAX][MAX],nxc[MAX][MAX];
vi r[MAX],c[MAX];
char x[MAX][MAX];
vii v;

int ls,nx;
inline void del(int a,int b){
	ls = lsr[a][b], nx = nxr[a][b];
	if(ls)nxr[a][ls] = nx;
	if(nx)lsr[a][nx] = ls;
	
	ls = lsc[a][b], nx = nxc[a][b];
	if(ls)nxc[ls][b] = nx;
	if(nx)lsc[nx][b] = ls;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m){
		cin>>x[i][j];
		if(x[i][j]!='.'){
			r[i].pb(j);
			c[j].pb(i);
			v.pb({i,j});
		}
	}
	for(auto o:v){
		a = o.fi, b = o.se;
		rep(i,1,n){
			For(j,0,r[i].size()){
				if(j)lsr[i][r[i][j]] = r[i][j-1];
				if(j+1!=r[i].size())nxr[i][r[i][j]] = r[i][j+1];
			}
		}
		rep(i,1,m){
			For(j,0,c[i].size()){
				if(j)lsc[c[i][j]][i] = c[i][j-1];
				if(j+1!=c[i].size())nxc[c[i][j]][i] = c[i][j+1];
			}
		}
		nw = 0;
		while(1){
			++nw;
			if(x[a][b]=='R'){
				if(!nxr[a][b])break;
				na = a, nb = nxr[a][b];
			}
			else if(x[a][b]=='L'){
				if(!lsr[a][b])break;
				na = a, nb = lsr[a][b];
			}
			else if(x[a][b]=='D'){
				if(!nxc[a][b])break;
				na = nxc[a][b], nb = b;
			}
			else {
				if(!lsc[a][b])break;
				na = lsc[a][b], nb = b;
			}
			del(a,b);
			a = na, b = nb;
		}
		if(nw>mx)mx = nw, cnt = 0;
		if(nw==mx)++cnt;
	}
	cout<<mx<<" "<<cnt<<endl;
	return 0;
}