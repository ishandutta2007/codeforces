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

int n,mn,x[MAX],cnt[5],opt,res,z,y[5],nw;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	mn = MOD;
	rep(i,1,n)cin>>x[i], mn = min(mn,x[i]);
	rep(i,1,n)++cnt[x[i]-mn];
	if(!cnt[2]){
		cout<<n<<endl;
		rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
		return 0;
	}
	opt = n;
	z = min(cnt[0],cnt[2]);
	y[1] = cnt[1] + 2*z;
	y[0] = cnt[0] - z, y[2] = cnt[2] - z;
//	rep(i,0,2)cout<<cnt[i]<<' '; cout<<endl;
//	rep(i,0,2)cout<<y[i]<<' '; cout<<endl;
	while(y[1]>=0){
		nw = 0;
		rep(i,0,2)nw+= min(cnt[i],y[i]);
		if(nw<=opt)opt = nw, res = y[1];
		y[1]-= 2;
		++y[0], ++y[2];
	}
	cout<<opt<<endl;
	z = (cnt[1]-res)/2;
	y[1] = res;
	y[0] = cnt[0] + z, y[2] = cnt[2] + z;
	rep(i,0,2){
		rep(j,1,y[i])cout<<i+mn<<' ';
	}
	cout<<endl;
	return 0;
}