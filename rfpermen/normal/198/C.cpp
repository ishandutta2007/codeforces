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
const int MAX = 1e3+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 547;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double xp,yp,vp,rp,agp,x,y,v,r,dis,ag,prj,le,ri,mid,res,nxag,nx,ny,tg;

inline double pointToSegment(ard(2) a, ard(2) b, ard(2) o = {0., 0.}){
	/*
		if origin != {0,0}
		a[0]-= o[0], a[1]-= o[1];
		b[0]-= o[0], b[1]-= o[1];
	*/
	b[0]-= a[0], b[1]-= a[1];
	a[0] =-a[0], a[1] =-a[1];
	double len = hypot(b[0], b[1]);
	if(len < EPS){
		return hypot(a[0], a[1]);
	}
	double prj = (a[0]*b[0] + a[1]*b[1])/len; // a . b / len(b)
	a[0] =-a[0], a[1] =-a[1];
	if(prj <= 0. || prj >= len){
		return min(hypot(a[0], a[1]), hypot(b[0]+a[0], b[1]+a[1]));
	}
	a[0]+= b[0]/len*prj, a[1]+= b[1]/len*prj;
	return hypot(a[0], a[1]);
}

ard(2) ag1, ag2;
double alpha, beta;

inline double get(double mid){
	double ret;
	
	nxag = agp + vp*mid;
	nx = rp * cos(nxag);
	ny = rp * sin(nxag);
	
	prj = pointToSegment({nx, ny}, {x, y});
	
	if(prj >= r){ // garis dari (x, y) ke (nx, ny) tidak memotong lingkaran r
		ret = hypot(nx-x, ny-y);
	}
	else {
		ag2 = {nxag-beta, nxag+beta};
		ret = INF;
		rep(i,0,1)rep(j,0,1)ret = min(ret, acos(cos(ag1[i]-ag2[j])));
		ret = ret*r + tg;
	}
	
	return ret;
}

int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>xp>>yp>>vp;
	cin>>x>>y>>v>>r;
	
	rp = hypot(xp, yp);
	dis = hypot(x, y);
	agp = atan2(yp, xp);
	ag = atan2(y, x);
	
	ri = fabs(rp-dis) + (2.*pi*rp)/vp * 2.;
	vp/= rp; // convert speed into radiant / second
	
	tg = sqrt(dis*dis - r*r) + sqrt(rp*rp - r*r);
	alpha = acos(r/dis), beta = acos(r/rp);
	ag1 = {ag-alpha, ag+alpha};
	
	rep(iter,1,50){
		mid = (le + ri)/2.;
		
		res = get(mid);
		
		if(res/v<=mid)ri = mid;
		else le = mid;
	}
	
	cout<<le<<endl;
	return 0;
}