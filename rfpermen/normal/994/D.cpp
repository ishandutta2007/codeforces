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
//#define endl '\n'
const int MAX = 20+5;
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

int n,m,cnt,z;
pii x[MAX],y[MAX];
bool vis[MAX],vis2[MAX],a,b,st;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n){
		cin>>x[i].fi>>x[i].se;
		if(x[i].se<x[i].fi)swap(x[i].fi,x[i].se);
	}
	rep(i,1,m){
		cin>>y[i].fi>>y[i].se;
		if(y[i].se<y[i].fi)swap(y[i].fi,y[i].se);
	}
	rep(i,1,n){
		z = x[i].fi;
		a = b = 0;
		rep(j,1,m)if(x[i]!=y[j]){
			if(y[j].fi==z || y[j].se==z)a = 1;
		}
		z = x[i].se;
		rep(j,1,m)if(x[i]!=y[j]){
			if(y[j].fi==z || y[j].se==z)b = 1;
		}
		if(a && b)return cout<<"-1\n",0;
		st|= a|b;
		vis[x[i].fi]|= a, vis[x[i].se]|= b;
	}
	if(!st)return cout<<"-1\n",0;
	st = 0;
	rep(j,1,m){
		z = y[j].fi;
		a = b = 0;
		rep(i,1,n)if(x[i]!=y[j]){
			if(x[i].fi==z || x[i].se==z)a = 1;
		}
		z = y[j].se;
		rep(i,1,n)if(x[i]!=y[j]){
			if(x[i].fi==z || x[i].se==z)b = 1;
		}
		if(a && b)return cout<<"-1\n",0;
		st|= a|b;
		vis2[y[j].fi]|= a, vis2[y[j].se]|= b;
	}
	if(!st)return cout<<"-1\n",0;
	rep(i,1,9)if(vis[i])++cnt, z = i;
	if(cnt==1)cout<<z<<endl;
	else if(cnt)cout<<"0\n";
	else return 1;
	return 0;
}