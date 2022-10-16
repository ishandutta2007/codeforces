#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vector<ll>>
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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,le,ri,m1,m2;
double p,q,ans,a1,a2;
vector<ard(2)> v;
ard(2) x[MAX];

/*
a*x0 + b*y0 = p
a*x1 + b*y1 = q
pers 1 - pers 2 * x0/x1
b*y0 - b*y1*(x0/x1) = p - q*(x0/x1)
*/
inline double f(ard(2) x,ard(2) y){
	double b = (p-q*x[0]/x[1])/(y[0]-y[1]*x[0]/x[1]);
	return max(0.0,b) + max(0.0,(p-b*y[0])/x[0]);
}

int main(){
	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>p>>q;
	rep(i,1,n)cin>>x[i][0]>>x[i][1];
	sort(x+1,x+1+n);
	rep(i,1,n){
		while(!v.empty() && v.back()[1]<=x[i][1])v.pob();
		v.pb(x[i]);
	}
	n = 0;
	for(auto i:v)++n, x[n] = i;
	ans = INF;
	rep(i,1,n){
		ans = min(ans,max(p/x[i][0],q/x[i][1]));
		//masih gak yakin juga sih kenapa pake ternary search bisa ac :v
		le = i+1, ri = n;
		while(ri-le>5){
			m1 = le+ri>>1;
			m2 = m1+1;
			a1 = f(x[i],x[m1]), a2 = f(x[i],x[m2]);
			if(a1<a2)ri = m1-1;
			else le = m2+1;
			ans = min(ans,min(a1,a2));
		}
		rep(j,le,ri)a1 = f(x[i],x[j]), ans = min(ans,a1);
	}
	cout<<ans<<endl;
	return 0;
}