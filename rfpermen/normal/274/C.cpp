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
const int MAX = 1e2+5;
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

ll n,x[MAX],y[MAX],dx,dy,mx,my,c;
vector<arll(4)> v;
double ans,dis,cek;
bool st;

inline void add(int i, int j, int k){
	v.pb({(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]),i,j,k});
	return;
}

arll(3) l1,l2;
inline void make(int i,int j,arll(3) &line){
	// dx * y = dy * x + c1
	dy = x[i]-x[j];
	dx = y[i]-y[j];
	// Bikin garis tegak lurus jadi
	// dy * y = -dx * x + c2
	// dy * y + dx * x = c2
	swap(dx, dy);
	mx = x[i]+x[j]>>1;
	my = y[i]+y[j]>>1;
//	cout<<"<> "<<dx<<" "<<dy<<endl;
//	cout<<">< "<<mx<<" "<<my<<endl;
	c = dy*my + dx*mx;
	line = {dy,-dx,c};
	return;
}

inline int cross(pll a,pll b,pll c) {    // right hand rule
	ll v1 = a.first - c.first;    // (a-c) X (b-c)
	ll v2 = a.second - c.second;
	ll u1 = b.first - c.first;
	ll u2 = b.second - c.second;
	v1 = v1 * u2 - v2 * u1;
	if(v1){
		if(v1>0)v1 = 1;
		else v1 = -1;
	}
	return v1;
}

int main(){
	cout<<fixed<<setprecision(6);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i]>>y[i], x[i]*= 2, y[i]*= 2;
	double px,py;
	ll a,b,jk,ck,v1,v2;
	rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n){
		v.clear();
		add(i,j,k);
		add(i,k,j);
		add(j,k,i);
		sort(all(v));
		if(v[0][0]+v[1][0] == v[2][0]){
			a = v[2][1], b = v[2][2], c = v[2][3];
			mx = x[a]+x[b]>>1;
			my = y[a]+y[b]>>1;
			jk = (x[a]-mx)*(x[a]-mx) + (y[a]-my)*(y[a]-my);
			if(jk <= ans)continue;
			st = 0;
			v1 = cross({x[b],y[b]}, {x[c],y[c]}, {x[a],y[a]});
			rep(o,1,n)if(o!=i && o!=j && o!=k){
				ck = (x[o]-mx)*(x[o]-mx) + (y[o]-my)*(y[o]-my);
				if(ck < jk){
					st = 0;
					break;
				}
				else if(jk == ck && !st){
					v2 = cross({x[b],y[b]}, {x[o],y[o]}, {x[a],y[a]});
					st = (v1!=v2);
				}
			}
			if(st)ans = jk;
			continue;
		}
		if(v[0][0]+v[1][0]<v[2][0])continue;
		make(i, j, l1);
		make(i, k, l2);
		// dy1 * y = dx1 * x + c1
		// dy2 * y = dx2 * x + c2
		// y = y
		// (dx1 * x + c1) * dy2 = (dx2 * x + c2) * dy1
		// (dx1*dy2 - dx2*dy1) x = c2*dy1 - c1*dy2
		px = (double)(l2[2]*l1[0] - l1[2]*l2[0]) / (l1[1]*l2[0] - l2[1]*l1[0]);
		// y = (dx1 * px + c1) / dy1
		if(l1[0]==0){
			py = (double)(l2[1] * px + l2[2]) / l2[0];
		}
		else {
			py = (double)(l1[1] * px + l1[2]) / l1[0];
		}
//		ou3(i,j,k);
//		out(px, py);
//		db(l1);
//		db(l2);
		st = 1;
		dis = (x[i]-px)*(x[i]-px) + (y[i]-py)*(y[i]-py);
		if(dis <= ans)continue;
		rep(o,1,n){
			cek = (x[o]-px)*(x[o]-px) + (y[o]-py)*(y[o]-py);
			if(cek+EPS < dis){
				st = 0;
				break;
			}
		}
		if(st)ans = dis;
	}
	if(ans==0.)return cout<<"-1\n",0;
	cout<<sqrt(ans)/2.<<endl;
	return 0;
}