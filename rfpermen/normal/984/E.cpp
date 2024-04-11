#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,dp[MAX][9][716],x[MAX],y[MAX],rem[716][9],add[716][9],vis[10000],id,tmp;
 
int f(int nw,int pos,int mask){
	if(nw>n&&mask==1)return 0;
	if(dp[nw][pos][mask]!=-1)return dp[nw][pos][mask];
	int ret = MOD, msk;
	if(nw<=n&&add[mask][y[nw]]!=-1)ret = f(nw+1,x[nw],add[mask][y[nw]]) + abs(x[nw]-pos);
	rep(i,0,8){
		msk = rem[mask][i];
		if(msk!=mask)ret = min(ret,f(nw,i,msk) + abs(pos-i));
	}
	return dp[nw][pos][mask] = ret;
}
 
vector<int> v;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nw,nx;
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i], --x[i], --y[i]; x[n+1] = -1;
    rep(a,0,9)rep(b,0,9)rep(c,0,9)rep(d,0,9){
    	v.clear();
    	v.pb(a), v.pb(b), v.pb(c), v.pb(d);
    	sort(all(v));
    	nw = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
    	if(!vis[nw])vis[nw] = ++id;
    	nw = vis[nw];
    	v.clear();
    	if(add[nw][0])continue;
    	//remove
    	rep(k,1,9){
    		v.pb(a), v.pb(b), v.pb(c), v.pb(d);
    		for(auto &i:v)if(i==k)i = 0;
    		sort(all(v));
    		nx = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
    		if(!vis[nx])vis[nx] = ++id;
    		nx = vis[nx];
    		rem[nw][k-1] = nx;
    		v.clear();
		}
		//add
    	rep(k,1,9){
    		v.pb(a), v.pb(b), v.pb(c), v.pb(d);
    		sort(all(v));
    		if(v[0])add[nw][k-1] = -1;
    		else {
    			v[0] = k;
    			sort(all(v));
    			nx = v[0]*1000 + v[1]*100 + v[2]*10 + v[3];
	    		if(!vis[nx])vis[nx] = ++id;
	    		nx = vis[nx];
	    		add[nw][k-1] = nx;
			}
	    	v.clear();
		}
	}
    memset(dp,-1,sizeof dp);
    cout<<f(1,0,1)+n+n<<endl;
    return 0;
}