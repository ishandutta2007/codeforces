#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
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
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

typedef ll TD;      
namespace GEOM {
  typedef pair<TD,TD> Pt;  
  TD cross(Pt a, Pt b, Pt c) {    // right hand rule
    TD v1 = a.first - c.first;    // (a-c) X (b-c)
    TD v2 = a.second - c.second;
    TD u1 = b.first - c.first;
    TD u2 = b.second - c.second;
    return v1 * u2 - v2 * u1;
  }
  vector<Pt> createConvexHull(vector<Pt> &points) {
    sort(points.begin(), points.end());
    vector<Pt> ret;
    for (int i = 0; i < points.size(); i++) {
      while (ret.size() > 1 &&
        cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) <= 0)
        ret.pop_back();
      ret.push_back(points[i]);
    }
    for (int i = points.size() - 2, sz = ret.size(); i >= 0; i--) {
      while (ret.size() > sz &&
        cross(points[i], ret[ret.size()-1], ret[ret.size()-2]) <= 0)
        ret.pop_back();
      if (i == 0) break;
      ret.push_back(points[i]);
    }
    return ret;
  }
}

inline ll dist(pll a,pll b){
	return (a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se);
}
inline ll dot(pll a,pll b,pll c){
	a.fi-= c.fi, a.se-= c.se;
	b.fi-= c.fi, b.se-= c.se;
	return a.fi*b.fi + a.se*b.se;
}

int n,m,a,b,lps[MAX],nw;
vector<pll> v,u,x,y;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;;
	rep(i,1,n){
		cin>>a>>b;
		v.pb({a,b});
	}
	rep(i,1,m){
		cin>>a>>b;
		u.pb({a,b});
	}
	v = GEOM::createConvexHull(v);
	u = GEOM::createConvexHull(u);
	if(v.size()!=u.size())return cout<<"NO\n",0;
	rep(i,0,1)v.pb(v[i]), u.pb(u[i]);
	ll dis,cs;
	For(i,2,v.size()){
		cs = dot(v[i],v[i-1],v[i-2]);
		dis = dist(v[i],v[i-1]);
		x.pb({cs,dis});
	}
	For(i,2,u.size()){
		cs = dot(u[i],u[i-1],u[i-2]);
		dis = dist(u[i],u[i-1]);
		y.pb({cs,dis});
	}
//	cout<<"_____\n";
//	for(pll i:x)cout<<i.fi<<" "<<i.se<<endl;
//	cout<<"_____\n";
//	for(pll i:y)cout<<i.fi<<" "<<i.se<<endl;
	For(i,0,x.size())y.pb(y[i]);
	For(i,1,x.size()){
		while(nw && x[nw]!=x[i])nw = lps[nw-1];
		if(x[nw]==x[i])lps[i] = ++nw;
	}
	nw = 0;
	For(i,0,y.size()){
		while(nw && x[nw]!=y[i])nw = lps[nw-1];
		if(x[nw]==y[i]){
			++nw;
			if(nw==x.size())return cout<<"YES\n",0;
		}
	}
	cout<<"NO\n";
	return 0;
}