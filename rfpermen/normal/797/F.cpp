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
const int block = 320;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,x[MAX],a,b,ttl,le;
pii y[MAX];
ll dp[2][MAX],val;
bool ls, nw;

int main(){
//	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>x[i];
	sort(x+1,x+1+n);
	rep(i,1,m){
		cin>>a>>b;
		y[i] = {a,b};
		ttl+= b;
	}
	if(ttl<n)return cout<<"-1\n",0;
	
	sort(y+1,y+1+m);
	ttl = 0;
	int nx;
	rep(i,1,n)dp[0][i] = dp[1][i] = INF;
	nw = 1;
	rep(i,1,m){
		nx = min(n, ttl+y[i].se);
		
		le = val = 0;
		rep(j,1,nx){
			val+= abs(x[j]-y[i].fi);
			while(le+1<min(j,ttl+1) && dp[ls][le]+abs(x[le+1]-y[i].fi)>=dp[ls][le+1]){
				++le;
				val-= abs(x[le]-y[i].fi);
			}
			if(le+y[i].se<j)++le, val-= abs(x[le]-y[i].fi);
			dp[nw][j] = min(dp[ls][j], dp[ls][le] + val);
		}
		ttl = nx;
		nw^= 1, ls^= 1;
	}
	cout<<dp[ls][n]<<endl;
	return 0;
}
/*
Penjelasan
dp[i][j] = sum dis kalau sekarang lagi ada di hole i, dan udh j tikus yang masuk hole
transisinya itu mau cari dp[i-1][le]+val yang paling optimal

nanti le nya jadi sejenis sliding window

Solusi salah:
awalnya geser pointer le itu bandingin dis jarak tikus le+1 ke lubang i dengan dibandingin 
ke lubang yang bikin dp[i-1][le+1] optimal,
tapi ternyata ada counter ketika

7 3
7 7 8 9 10 10 12
0 3
5 3
16 7

nanti jarak untuk tikus bakal ke lubang bakal jadi
7 7 8
2 2 3 4 5 5
2 2 3 7 6 6 4 (atau bisa juga 9 9 8 7 6 6 4)

perhatikan pas lagi lubang 3, bakal selalu inferior dibanding optimal di posisi 4,5,6 jadi le bakal geser terus jadi 4,5,6
padahal kalau mau optimal harus le=3 jadinya
[0..0][1..3][4..7]

jadi kalau mau geser itu yang dibandingin jangan distance nya tapi mending langsung
cek value dp nya jadi lebih optimal kalau digeser le nya atau tidak (jadinya lebih general juga perbandingannya)

Note: Tapi masih belum tau juga sih kenapa kayak gituh aja langsung bisa ac :v (mungkin karena monoton?)
*/