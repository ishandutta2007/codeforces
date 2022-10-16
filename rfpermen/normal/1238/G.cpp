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
const int MAX = 5e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,-1,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll tc,n,m,k,co,t,a,b,ans,nw,len,cnt,rem,mn;
arll(3) x[MAX];
map<int,int> s;

int main(){
//	cout<<fixed<<setprecision(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>m>>k>>co;
		rep(i,1,n){
			cin>>t>>a>>b;
			x[i] = {t,b,a};
		}
		if(co>=m){
			cout<<"0\n",0;
			continue;
		}
		sort(x+1,x+1+n);
		s.clear();
		len = s[0] = co;
		ans = nw = 0;
		auto it = s.begin();
		auto en = s.rbegin();
		rep(i,1,n){
			len-= x[i][0]-nw;
			while(s.size() && nw!=x[i][0]){
				it = s.begin();
				b = it->fi, a = it->se;
				s.erase(it);
				if(nw+a<=x[i][0]){
					nw+= a;
					ans+= b*a;
				}
				else {
					ans+= (x[i][0]-nw)*b;
					a-= (x[i][0]-nw);
					nw = x[i][0];
					s[b] = a;
				}
			}
			if(nw!=x[i][0])break;
			rem = x[i][2];
			if(len!=k){
				mn = min(k-len, rem);
				rem-= mn;
				len+= mn;
				s[x[i][1]]+= mn;
			}
			cnt = 0;
			while(rem && s.size()){
				en = s.rbegin();
				b = en->fi, a = en->se;
				if(b<=x[i][1])break;
				s.erase(b);
				mn = min(rem, a);
				a-= mn;
				rem-= mn;
				s[x[i][1]]+= mn;
				if(a)s[b] = a;
			}
		}
		while(s.size() && nw!=m){
			it = s.begin();
			b = it->fi, a = it->se;
			s.erase(it);
			if(nw+a<=m){
				nw+= a;
				ans+= b*a;
			}
			else {
				ans+= (m-nw)*b;
				a-= (m-nw);
				nw = m;
				s[b] = a;
			}
		}
		if(nw!=m)ans = -1;
		cout<<ans<<endl;
	}
	return 0;
}