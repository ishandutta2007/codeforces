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
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}

int n,cnt;
ari(4) a[MAX];
vector<ari(2)> v;
set<int> x,y;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n){
		rep(j,0,3)cin>>a[i][j];
		v.pb({a[i][0],0});
		v.pb({a[i][2],1});
	}
	sort(all(v));
	for(auto i:v){
		if(!i[1]){
			++cnt;
			if(cnt>=n-1)x.insert(i[0]);
		}
		else {
			if(cnt>=n-1)x.insert(i[0]);
			--cnt;
		}
	}
	
	v.clear();
	rep(i,1,n){
		v.pb({a[i][1],0});
		v.pb({a[i][3],1});
	}
	sort(all(v));
	for(auto i:v){
		if(!i[1]){
			++cnt;
			if(cnt>=n-1)y.insert(i[0]);
		}
		else {
			if(cnt>=n-1)y.insert(i[0]);
			--cnt;
		}
	}
	
	for(auto j:x)for(auto k:y){
		cnt = 0;
		rep(i,1,n)cnt+= a[i][0]<=j && j<=a[i][2] && a[i][1]<=k && k<=a[i][3];
		if(cnt>=n-1)return cout<<j<<" "<<k<<endl,0;
	}
	return 0;
}