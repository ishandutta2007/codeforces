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
const int MAX = 5e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 547;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int tc,n,x[MAX],cnt[MAX],mx,dp[MAX],z[MAX],o,ans,cb;
vi v[MAX],cd[MAX];
bool st[MAX][MAX];

int f(int nw){
	if(nw>n)return 0;
	int &ret = dp[nw];
	if(ret!=-1)return ret;
	ret = -MOD;
	if(st[nw][n])ret = 0;
	if(x[nw]==o)ret = max(ret, f(nw+1) + 1);
	for(int i:v[o]){
		if(i<=nw)break;
		if(st[nw][i-1])ret = max(ret, f(i));
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n;
		rep(i,1,n){
			z[i] = 0;
			v[i].clear();
			rep(j,i+1,n)st[i][j] = 0;
		}
		rep(i,1,n)cin>>x[i], v[x[i]].pb(i), cd[i].clear(), z[x[i]]++;
		
		rep(i,1,n){
			rep(j,1,n)cnt[j] = 0;
			mx = 0;
			rep(j,i,n){
				++cnt[x[j]];
				mx = max(mx, cnt[x[j]]);
				if((j-i)&1)st[i][j] = mx*2<=j-i+1;
			}
		}
		rep(i,1,n){
			if((n-z[i])&1)--z[i];
			if(z[i]>0)cd[z[i]].pb(i);
			reverse(all(v[i]));
		}
		revsort(z+1,z+1+n);
		ans = 0;
		
		rap(O,n,1){
			if(O<=ans)break;
			shuffle(all(cd[O]), rng);
			for(int j:cd[O]){
				if(O<=ans)break;
				rep(i,1,n)dp[i] = -1;
				o = j;
				ans = max(ans, f(1));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}