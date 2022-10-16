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
const int MAX = 3e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int k,n,m,r,c,a,b,z[MAX],nr,nc,ls,id,grid[MAX][MAX];
ll ans;
set<int> x,y;
pii qx[MAX], qy[MAX];
char mv[MAX];

inline void upd(int a=r,int b=c){
	x.insert(a+1), x.insert(a);
	y.insert(b+1), y.insert(b);
	return;
}

inline void move(char mv, int z){
	nr = r, nc = c;
	if(mv=='U')nr-= z;
	else if(mv=='D')nr+= z;
	else if(mv=='R')nc+= z;
	else nc-= z;
	return;
}

void dfs(int r,int c){
	int nr, nc;
	grid[r][c] = 2;
	rep(i,0,3){
		nr = r+dr[i], nc = c+dc[i];
		if(nr<0 || nc<0 || nr>n+1 || nc>m+1 || grid[nr][nc])continue;
		dfs(nr, nc);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>k;
	upd();
	rep(i,1,k){
		cin>>mv[i]>>z[i];
		move(mv[i], z[i]);
		r = nr, c = nc;
		upd();
	}
	auto it = x.begin();
	ls = *it, ++it;
	while(it!=x.end()){
		++n;
		if(ls==0)a = n;
		qx[n] = {ls,(*it)-ls};
		ls = *it;
		++it;
	}
	it = y.begin();
	ls = *it, ++it;
	while(it!=y.end()){
		++m;
		if(ls==0)b = m;
		qy[m] = {ls,(*it)-ls};
		ls = *it;
		++it;
	}
	
	r = c = 0;
	grid[a][b] = 1;
	rep(i,1,k){
		move(mv[i], z[i]);
		if(mv[i]=='U'){
			while(r!=nr){
				--a;
				r = qx[a].fi;	
				grid[a][b] = 1;
			}
		}
		else if(mv[i]=='D'){
			while(r!=nr){
				++a;
				r = qx[a].fi;	
				grid[a][b] = 1;
			}
		}
		else if(mv[i]=='L'){
			while(c!=nc){
				--b;
				c = qy[b].fi;
				grid[a][b] = 1;
			}
		}
		else {
			while(c!=nc){
				++b;
				c = qy[b].fi;
				grid[a][b] = 1;
			}
		}
	}
	dfs(0,0);
	rep(i,1,n){
//		rep(j,1,m)cout<<grid[i][j]; cout<<endl;
		rep(j,1,m)if(grid[i][j]<2)ans+= (ll)qx[i].se * qy[j].se;
	}
	cout<<ans<<endl;
	return 0;
}