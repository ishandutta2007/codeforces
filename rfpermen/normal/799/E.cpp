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
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

ll n,m,k,a,b,c,d,o,id[4],nw;
ll ans;
pll x[MAX];
vector<ll> v[4],z[4];
vector<pll> mn;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i].fi;
    cin>>o;
    rep(i,1,o)cin>>a, x[a].se|= 1;
    cin>>o;
    rep(i,1,o)cin>>a, x[a].se|= 2;
    sort(x+1,x+1+n);
    a = b = 0;
    rep(i,1,m){
    	ans+= x[i].fi;
    	if(x[i].se&1)++a;
    	if(x[i].se&2)++b;
	}
	if(a>=k && b>=k)return cout<<ans<<endl,0;
	ans = INF;
	rep(j,0,3)z[j].pb(0);
	rep(i,1,n){
		v[x[i].se].pb(x[i].fi);
		z[x[i].se].pb(z[x[i].se].back()+x[i].fi);
	}
	o = min(k,(ll)v[3].size());
	rep(i,0,o){
		a = k-i;
		if(v[1].size()<a || v[2].size()<a || i+a*2>m)continue;
		id[1] = max(id[1],a);
		id[2] = max(id[2],a);
		id[3] = max(id[3],(ll)i);
		if(id[1]==a+1)--id[1];
		if(id[2]==a+1)--id[2];
		
		while(id[0]+id[1]+id[2]+id[3]<m){
			mn.clear();
			rep(j,0,3)if(id[j]!=v[j].size())mn.pb({v[j][id[j]],j});
			sort(all(mn));
			assert(!mn.empty());
			id[mn[0].se]++;
		}
		nw = 0;
//		rep(j,0,3)cout<<id[j]<<" "<<z[j].size()<<endl; cout<<endl;
		rep(j,0,3)nw+= z[j][id[j]];
		ans = min(ans,nw);
		if(id[1]>a && id[2]>a)break;
	}
	if(ans==INF)ans = -1;
	cout<<ans<<endl;
	return 0;
}