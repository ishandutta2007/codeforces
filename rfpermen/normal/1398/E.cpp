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
const int MAX = 2e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,ty,x,cnt;
ll sm,nw;
set<pii> a,b;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>ty>>x;
		if(x<0){
			x = -x;
			sm-= x;
			if(ty){
				if(a.count({x,ty})){
					a.erase({x,ty});
					nw-= (*b.begin()).fi;
					if((*b.begin()).se)--cnt;
					a.insert(*b.begin());
					b.erase(*b.begin());
				}
				else {
					b.erase({x,ty});
					--cnt, nw-= x;
				}
			}
			else {
				if(a.count({x,ty})){
					a.erase({x,ty});
				}
				else {
					nw-= x;
					b.erase({x,ty});
					nw+= (*a.rbegin()).fi;
					if((*a.rbegin()).se)++cnt;
					b.insert(*a.rbegin());
					a.erase(*a.rbegin());
				}
			}
		}
		else {
			sm+= x;
			if(ty){
				a.insert({x,ty});
				nw+= (*a.rbegin()).fi;
				if((*a.rbegin()).se)++cnt;
				b.insert(*a.rbegin());
				a.erase(*a.rbegin());
			}
			else {
				nw+= x;
				b.insert({x,ty});
				nw-= (*b.begin()).fi;
				if((*b.begin()).se)--cnt;
				a.insert(*b.begin());
				b.erase(*b.begin());
			}
		}
		if(!sm)cout<<"0\n";
		else {
			if(cnt != b.size())cout<<sm+nw<<endl;
			else {
				if(cnt){
					if(a.size()){
						cout<<sm+nw-(*b.begin()).fi+(*a.rbegin()).fi<<endl;
					}
					else {
						cout<<sm+nw-(*b.begin()).fi<<endl;
					}
				}
				else cout<<sm<<endl;
			}
		}
	}
	return 0;
}