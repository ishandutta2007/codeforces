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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 5;
inline ll pw(ll x,ll y,ll md){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,k,hs[MAX],id;
vi r,c;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(max(n,m)==1)return cout<<"YES\n1\n",0;
	if(n==3 && m==3)return cout<<"YES\n1 3 4\n5 7 6\n9 2 8\n",0;
	if(max(n,m)<4)return cout<<"NO\n",0;
	
	k = n*m;
	if(n>m){
		rep(j,1,m)rep(i,1,n){
			hs[++id] = (i-1)*m+j;
		}
		swap(n, m);
		st = 1;
	}
	vvi x(n+2, vi(m+2,0));
	int mid = m>>1;
	r = c = {0};
	rep(i,1,m){
		r.pb(mid+(i+1)/2);
		r.pb((i+1)/2);
		i++;
	}
	if(n==2 || n==3){
		r.pb(0);
		rep(j,1,m)x[1][j] = r[j]+m;
		if(m&1){
			r[m+1] = r[1];
			rep(j,1,m)x[2][j] = r[j+1];
		}
		else {
			reverse(all(r));
			rep(j,1,m)x[2][j] = r[j];
		}
		rep(j,1,m)x[3][j] = r[j]+2*m;
	}
	else {
		mid = n>>1;
		rep(i,1,n){
			c.pb(mid+(i+1)/2);
			c.pb((i+1)/2);
			i++;
		}
		rep(i,1,n)rep(j,1,m)x[i][j] = (c[i]-1)*m + r[j];
	}
	cout<<"YES\n";
	if(!st){
		rep(i,1,n){
			rep(j,1,m)cout<<x[i][j]<<" ";
			cout<<endl;
		}
	}
	else {
		rep(j,1,m){
			rep(i,1,n)cout<<hs[x[i][j]]<<" ";
			cout<<endl;
		}
	}
	return 0;
}