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
//#define lll __int128
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
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vlll vector<pll>
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
const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tc,n,m,ans,pos,r,c,nr,nc;
vi vis[MAX];
vii par[MAX];
vector<char> x[MAX];
deque<pii> dq;

int main(){
//	cout<<fixed<<setprecision(3);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>m;
		rep(i,0,n+1){
			x[i].resize(m+2);
			vis[i].resize(m+2);
			par[i].resize(m+2);
		}
		rep(i,1,n){
			rep(j,1,m){
				cin>>x[i][j];
				vis[i][j] = -1;
			}
		}
		
		rep(i,1,n)rep(j,1,m)if(x[i][j]=='#'){
			rep(k,0,3){
				nr = i+dr[k], nc = j+dc[k];
				if(x[nr][nc]!='#')x[nr][nc] = 'X';
			}
		}
		
		rep(i,1,n)if(x[i][1]!='X'){
			if(x[i][1]=='#'){
				vis[i][1] = 0;
				dq.pf({i,1});
			}
			else {
				vis[i][1] = 1;
				dq.pb({i,1});
			}
		}
		
		while(!dq.empty()){
			r = dq.front().fi;
			c = dq.front().se;
			dq.pof();
			rep(k,4,7){
				nr = r+dr[k], nc = c+dc[k];
				if(nr<1 || nc<1 || nr>n || nc>m || x[nr][nc]=='X' || vis[nr][nc]!=-1)continue;
				if(x[nr][nc]=='#'){
					vis[nr][nc] = vis[r][c];
					par[nr][nc] = {r,c};
					dq.pf({nr,nc});
				}
				else {
					vis[nr][nc] = vis[r][c]+1;
					par[nr][nc] = {r,c};
					dq.pb({nr,nc});
				}
			}
		}
		
		ans = MOD;
		c = m;
		rep(i,1,n)if(vis[i][m]!=-1 && vis[i][m]<ans){
			ans = vis[i][m];
			r = i;
		}
		
		if(ans==MOD){
			cout<<"NO\n";
		}
		else {
			while(1){
				x[r][c] = '#';
				if(c==1)break;
				nr = par[r][c].fi;
				nc = par[r][c].se;
				r = nr, c = nc;
			}
			cout<<"YES\n";
			rep(i,1,n){
				rep(j,1,m){
					if(x[i][j]=='#')cout<<'#';
					else cout<<'.';
				}
				cout<<endl;
			}
		}
	}
	return 0;
}