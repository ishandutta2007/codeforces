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
//#define endl '\n'
const int MAX = 5e5+5;
const ll MOD = 10020000007;
const ll MOD2 = 2078628313;
const ll INF = 2e18;
const int dr[]={1,0,0,-1,1,1,-1,-1};
const int dc[]={0,1,-1,0,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vi x,a,b,c,d;

void split(){
	a.clear();
	b.clear();
	c.clear();
	int sz = x.size()/3;
	For(i,0,sz){
		a.pb(x[i]);
		b.pb(x[i+sz]);
		c.pb(x[i+sz+sz]);
	}
	if(x.size()%3>=1){
		a.pb(x[sz*3]);
		if(x.size()%3>=2){
			b.pb(x[sz*3+1]);
		}
	}
	return;
}

void merge(vi a,vi b){
	x.clear();
	for(auto i:a)x.pb(i);
	for(auto i:b)x.pb(i);
	return;
}

bool r1,r2;
string s;

int cnt;
bool que(vi a, vi b){
	cout<<"?";
	cout<<" "<<a.size()+b.size();
	for(int i:a)cout<<" "<<i;
	for(int i:b)cout<<" "<<i;
	cout<<endl;
	cin>>s;
//	s = "YES";
//	++cnt;
	return s=="YES";
}


void split2(){
	a.clear();
	b.clear();
	c.clear();
	d.clear();
	int sz = x.size()/4;
	For(i,0,sz){
		a.pb(x[i]);
		b.pb(x[i+sz]);
		c.pb(x[i+sz+sz]);
		d.pb(x[i+sz+sz+sz]);
	}
	if(x.size()%4>=1){
		a.pb(x[sz*4]);
		if(x.size()%4>=2){
			b.pb(x[sz*4+1]);
			if(x.size()%4>=3){
				c.pb(x[sz*4+2]);
			}
		}
	}
	return;
}

void merge2(vi a,vi b,vi c){
	x.clear();
	for(auto i:a)x.pb(i);
	for(auto i:b)x.pb(i);
	for(auto i:c)x.pb(i);
	return;
}


int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
//	n = 1e5;
	rep(i,1,n)x.pb(i);
	while(x.size()>3){
//		db(x.size());
		split2();
		r1 = que(a,b);
		if(r1){
			r2 = que(c,{});
			if(r2)merge2(a,b,c);
			else merge2(a,b,d);
		}
		else {
			r2 = que(a,{});
			if(r2)merge2(a,c,d);
			else merge2(b,c,d);
		}
	}
	while(x.size()>2){
		split();
		r1 = que(a,b);
		r2 = que(b,c);
		if(r1 && r2){
			r2 = que(b,c);
			if(r2){
				merge(b,c);
				continue;
			}
			r1 = que(a,b);
		}
		if(!r1 && !r2){
			merge(a,c);
		}
		else if(r1){
			merge(a,b);
		}
		else if(r2){
			merge(b,c);
		}
		else {
			assert(0);
		}
	}
//	db(cnt);
	for(int i:x){
		cout<<"! "<<i<<endl;
		cin>>s;
		if(s==":)")break;
	}
	return 0;
}