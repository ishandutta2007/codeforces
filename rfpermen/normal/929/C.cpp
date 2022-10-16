#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define FOR(i,n,N) for(int i=(n);i< (N);++i)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n[4],x;
ll y[4],ans;
vector<pii> v;

int main(){
//	cout<<fixed<<setprecision(4);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	rep(j,1,3)cin>>n[j];
	rep(j,1,3){
		rep(i,1,n[j])cin>>x, v.pb({x,j});
	}
	sort(all(v));
	x = 0;
	for(pii i:v){
		while(x!=v.size() && v[x].fi<=(i.fi<<1)){
			++y[v[x].se];
			++x;
		}
		--y[i.se];
		if(i.se==1){
			ans+= (y[2]*(y[2]-1)/2)*(y[3]*(y[3]-1)*(y[3]-2)/6);
		}
		else if(i.se==2){
			ans+= y[1]*y[2]*(y[3]*(y[3]-1)*(y[3]-2)/6);
		}
		else {
			ans+= y[1]*(y[2]*(y[2]-1)/2)*(y[3]*(y[3]-1)/2);
		}
//		ans+= y[1]*(y[2]*(y[2]-1)/2)*(y[3]*(y[3]-1)*(y[3]-2)/6);
	}
	cout<<ans<<endl;
	return 0;
}