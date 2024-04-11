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
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={0,0,-1,1,1,1,-1,-1};
const int dc[]={1,-1,0,0,1,-1,-1,1};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll a,b,c;
#define pdd pair<double,double>
pdd j,k;
void en(ll x1,ll y1,ll x2,ll y2){
	cout<<abs(x1-x2)+abs(y1-y2)<<endl;
	exit(0);
}

inline double X(double y){
	return -(b*y + c)/a;
}
inline double Y(double x){
	return -(a*x + c)/b;
}

inline double dist(pdd a,pdd b){
	return hypot(a.fi-b.fi,a.se-b.se);
}

double x,y;

int main(){
	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll x1,y1,x2,y2;
	cin>>a>>b>>c;
	cin>>x1>>y1>>x2>>y2;
	if(x1>x2)swap(x1,x2), swap(y1,y2);
	if(!a || !b || x1==x2 || y1==y2)en(x1,y1,x2,y2);
	if(y1>y2){
		if(a*b<0)en(x1,y1,x2,y2);
	}
	else {
		if(a*b>0)en(x1,y1,x2,y2);
	}
	x = X(y1);
	y = X(y2);
	if(y<=x1 || x>=x2)en(x1,y1,x2,y2);
	if(x<=x1)j = {x1,Y(x1)};
	else j = {x,y1};
	if(y>=x2)k = {x2,Y(x2)};
	else k = {y,y2};
	cout<<dist({x1,y1},j) + dist(j,k) + dist(k,{x2,y2})<<endl;
	return 0;
}