#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int cnt,id,z[MAX],hit[MAX],y,dp[55][10005];
ll x,k,pre[55],res[55][55],ans,tmp;
vector<pair<ll,int>> fc;
bool vis[55];

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

void bf(int pos,ll num){
	if(pos==id){
		tmp = 1;
		asd(i,0,pos)tmp = tmp*res[z[i]][hit[i]]%MOD;
		ans+= num%MOD*tmp%MOD;
//		out(num,tmp);
		return;
	}
	rep(i,0,fc[pos].se){
		bf(pos+1,num);
		num*= fc[pos].fi;
		++hit[pos];
	}
	hit[pos] = 0;
	return;
}

int f(int x,int k){
	if(!k)return x==y;
	if(dp[x][k]!=-1)return dp[x][k];
	ll ret = 0;
	rep(i,x,y)ret+= f(i,k-1)*pre[i+1]%MOD;
	return dp[x][k] = ret%MOD;
}

void cp(int a){
	if(vis[a])return;
	vis[a] = 1;
	mems(dp,-1);
	y = a;
	rep(i,0,a)res[a][i] = f(i,k);
//	cout<<"____\n";
//	db(a);
//	rep(i,0,a)cout<<res[a][i]<<' '; cout<<endl;
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,0,52)pre[i] = pw(i,MOD-2);
    cin>>x>>k;
    
    for(ll i = 2; i*i<=x; ++i)if(x%i==0){
    	cnt = 0;
    	while(x%i==0)x/= i, ++cnt;
    	fc.pb({i,cnt});
    	z[id++] = cnt;
    	cp(cnt);
	}
	if(x!=1)fc.pb({x,1}), z[id++] = 1, cp(1);
	
	bf(0,1);
	ans%= MOD;
	cout<<ans<<endl;
    return 0;
}