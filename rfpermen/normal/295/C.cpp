#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
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
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>= 1;
	}
	return ret;
}

ll fc[55],pre[55][55];
int n,k,a,b,x,y,c,d,dp[55][55][2],vis[55][55][2],val;
bool mv;
queue<piii> q;

inline void ins(int x,int y){
	if(vis[x][y][mv]==-1){
		vis[x][y][mv] = val;
		q.push({mv,{x,y}});
	}
	return;
}

int f(int x,int y,bool mv){
	if(dp[x][y][mv]!=-1)return dp[x][y][mv];
	if(!x&&!y&&mv)return dp[x][y][mv] = 1;
	ll ret = 0;
	int val = vis[x][y][mv]+1;
	mv^= 1;
	if(mv){
		rep(i,0,x)rep(j,0,y){
			if(i+j*2>k)break;
			if((i||j) && vis[x-i][y-j][mv]==val)ret+= f(x-i,y-j,mv)*pre[x][i]%MOD*pre[y][j]%MOD;
		}
	}
	else {
		int c = a-x, d = b-y;
		rep(i,0,c)rep(j,0,d){
			if(i+j*2>k)break;
			if((i||j) && vis[x+i][y+j][mv]==val)ret+= f(x+i,y+j,mv)*pre[c][i]%MOD*pre[d][j]%MOD;
		}
	}
	return dp[x][y][mv^1] = ret%MOD;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fc[0] = 1;
    rep(i,1,50)fc[i] = fc[i-1]*i%MOD;
    rep(i,0,50)rep(j,0,i)pre[i][j] = fc[i]*pw(fc[j],MOD-2)%MOD*pw(fc[i-j],MOD-2)%MOD;
    
    cin>>n>>k;
    k/= 50;
    rep(i,1,n){
    	cin>>x;
    	if(x==50)++a;
    	else ++b;
	}
	mems(vis,-1);
	vis[a][b][0] = 0;
	q.push({0,{a,b}});
	while(!q.empty()){
		x = q.front().sf, y = q.front().ss, mv = q.front().fi, q.pop();
		val = vis[x][y][mv]+1;
		mv^=1;
		if(mv){
			rep(i,0,x)rep(j,0,y){
				if(i+j*2>k)break;
				if(i||j)ins(x-i,y-j);
			}
		}
		else {
			c = a-x, d = b-y;
			rep(i,0,c)rep(j,0,d){
				if(i+j*2>k)break;
				if(i||j)ins(x+i,y+j);
			}
		}
	}
	cout<<vis[0][0][1]<<endl;
	mems(dp,-1);
	cout<<f(a,b,0)<<endl;
    return 0;
}