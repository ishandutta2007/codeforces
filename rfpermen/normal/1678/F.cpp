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
const int MAX = 2e6+5;
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

//observasi:
//misal inversion awal itu begini
//0 1 2 3 0 5
//setelah 1x operasi jadi
//0 1 2 0 4 0
//setelah 1x operasi lagi jadi
//0 1 0 3 0 0
//
//pola operasi nya itu
//pindahin elemen paling pertama ke belakang, terus kurangin inversion 2..n sebanyak 1
//tapi batasin sama 0.
//
//jadi kalau lakuin operasi sebanyak k kali bakal gak perduliin k elemen pertama
//dan sisa nya bakal pindah ke posisi depan dan dikurangin sebanyak k.
//
//makanya kalau awalnya yang bisa banyak variasi itu kalau inversionnya 0,
//karena max(x-k,0) = 0 ada k nilai x non negatif yang memenuhi, selain itu cuma ada 1 nilai
//Note: untuk setiap konfigurasi inversion valid pasti punya tepat 1 konfigurasi permutasi makanya tekniknya dibanding bayangin solve permutasi, lebih gampang kerjain kalau kita anggap permutasi sebagai inversion karena pemetaannya pasti ada.

ll fc[MAX];
inline void combin(int n){
	fc[0] = 1;
	rep(i,1,n){
		fc[i] = fc[i-1]*i%MOD;
	}
}
ll tc,n,k,x[MAX],ans;
 
int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	combin(MAX-5);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>k;
		rep(i,1,n)cin>>x[i];
		bool st = 1;
		rep(i,1,k)if(x[n-i+1]>0)st = 0;
		if(!st){
			cout<<"0\n";
			continue;
		}
		n-= k;
		ans = fc[k];
		rep(i,1,n){
			if(x[i]==-1)ans = ans*(k+i)%MOD;
			else if(x[i]==0)ans = ans*(k+1)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}