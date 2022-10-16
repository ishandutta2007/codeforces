#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,t,z,len,gb,bt,sz,tgt;
ll way[51][51][51][4],dp[4][51][51][2501],ans,jlh,fc[51];
vector<int> x[4];
vector<pll> y[4];

ll f(int a,int b,int c,int ls){
	if(!a&&!b&&!c)return 1;
	ll &ret = way[a][b][c][ls];
	if(ret!=-1)return ret;
	ret = 0;
	if(a&&ls!=1)ret+=f(a-1,b,c,1);
	if(b&&ls!=2)ret+=f(a,b-1,c,2);
	if(c&&ls!=3)ret+=f(a,b,c-1,3);
	while(ret>MOD)ret-=MOD;
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fc[0] = 1;
    rep(i,1,50)fc[i] = (fc[i-1]*i)%MOD;
    cin>>n>>t;
    rep(i,1,n){
    	cin>>len>>z;
    	x[z].pb(len);
	}
	memset(way,-1,sizeof way);
	rep(i,1,3){
		dp[i][0][0][0] = 1, bt = 0, sz = x[i].size();
		for(int j = 0; j<sz; ++j){
			rep(o,0,j){
				rep(k,0,bt){
					if(!dp[i][j][o][k])continue;
					dp[i][j+1][o][k]+= dp[i][j][o][k];
					ll &tmp = dp[i][j+1][o+1][k+x[i][j]];
					tmp+= dp[i][j][o][k];
					while(tmp>MOD)tmp-=MOD;
				}
			}
			bt+=x[i][j];
		}
		rep(o,0,sz)rep(k,0,bt)if(dp[i][sz][o][k])y[i].pb({o,k});
	}
	int a = 1,b = 2,c = 3;
	if(y[c].size()<y[a].size())swap(a,c);
	if(y[c].size()<y[b].size())swap(b,c);
	sz = x[c].size();
	int sza = x[a].size(), szb = x[b].size();
	
	for(auto i:y[a]){
		for(auto j:y[b]){
			if(i.se+j.se>t)continue;
			tgt = t - i.se - j.se;
			jlh = dp[a][sza][i.fi][i.se] * dp[b][szb][j.fi][j.se] % MOD * (fc[i.fi]*fc[j.fi]%MOD) % MOD;
			rep(o,0,sz){
				if(!dp[c][sz][o][tgt])continue;
				ans = (ans + f(i.fi,j.fi,o,0) * (jlh * (dp[c][sz][o][tgt]*fc[o]%MOD) % MOD))%MOD;
			}
		}
	}
	
	cout<<ans<<endl;
    return 0;
}