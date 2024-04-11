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
const int MAX = 1e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 20;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tc,n,N,a,b,p[MAX],q[MAX*MAX],vis[MAX][MAX];
string s[MAX][MAX];
vi v[MAX],m[MAX*MAX];
vii e;
bool st[MAX][MAX],ad;

int par(int *p,int z){
	if(p[z]==z)return z;
	return p[z] = par(p, p[z]);
}

void dfs(int nw,int at){
	for(int i:v[nw])if(i!=at){
		vis[a][i] = vis[a][nw]+1;
		dfs(i, nw);
	}
	return;
}

inline bool validate(){
	For(i,0,n)v[i].clear();
	for(auto i:e){
		v[i.fi].pb(i.se);
		v[i.se].pb(i.fi);
	}
	
	For(i,0,n){
		a = i;
		vis[i][i] = 0;
		dfs(i, -1);
	}
	
//	For(i,0,n){
//		For(j,0,n)cout<<vis[i][j]<<" ";
//		cout<<endl;
//	}
	
	For(i,0,n){
		For(j,i+1,n){
			For(k,0,n){
				if((s[i][j][k]=='1') ^ (vis[i][k]==vis[j][k]))return false;
			}
		}
	}
	
	return true;
}
int c,d;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n;
		
		N = n*n;
		For(i,0,N){
			q[i] = i;
			m[i].clear();
		}
		
		ad = 1;
		For(i,0,n){
			For(j,i+1,n){
				cin>>s[i][j];
				For(k,0,n){
					a = par(q, i*n + k), b = par(q, j*n + k);
					c = par(q, k*n + i), d = par(q, k*n + j);
					if(s[i][j][k]=='1')q[b] = q[c] = q[d] = a;
					else {
						if(a==b || c==d)ad = 0;
					}
				}
			}
		}
		if(!ad){
			cout<<"No\n";
			continue;
		}
		
//		e = {{1,2},{1,4},{2,3},{2,5}};
//		cout<<validate()<<endl;
//		return 0;
		
		For(i,0,N)m[par(q,i)].pb(i);
//		For(o,0,N){
//			cout<<m[o].size()<<endl;
//		}
		
		ad = 0;
		For(o,0,N)if(m[o].size()>=n-1){
//			cout<<"HELLO\n";
			For(i,0,n)p[i] = i;
			ad = 1;
			for(auto i:m[o]){
				a = i/n, b = i%n;
				if(a>b)swap(a,b);
				if(par(p, a)!=par(p, b)){
					st[a][b] = 1;
					p[par(p, a)] = par(p, b);
					e.pb({a,b});
				}
				else {
					if(!st[a][b]){
						ad = 0;
						break;
					}
				}
			}
			
			ad&= e.size()==n-1;
			if(!ad){
				for(auto i:e)st[i.fi][i.se] = 0;
				e.clear();
				continue;
			}
			
			ad = validate();
			
			
			if(!ad){
				for(auto i:e)st[i.fi][i.se] = 0;
				e.clear();
				continue;
			}
			else break;
		}
		if(ad){
			cout<<"Yes\n";
			for(auto i:e){
				cout<<i.fi+1<<" "<<i.se+1<<endl;
				st[i.fi][i.se] = 0;
			}
			e.clear();
		}
		else {
			cout<<"No\n";
		}
	}
	return 0;
}