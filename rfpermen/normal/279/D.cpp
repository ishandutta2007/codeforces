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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
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
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,x[23],uj,msk,ans;
vector<int> av[23][23];
bool dp[2][1<<23],nw,ls,st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    --n;
    rep(i,0,n)cin>>x[i];
    rep(i,1,n){
    	st = 0;
    	rep(j,0,i)rep(k,j,i)if(x[j]+x[k]==x[i])av[i][j].pb(1<<k), st = 1;
    	if(!st)return cout<<"-1\n",0;
	}
    dp[0][1] = 1;
    nw = 1;
    rep(i,1,n){
    	uj = 1<<i;
    	rep(mask,1,8388607){
    		if(!dp[ls][mask])continue;
    		st = 0;
    		for(int k = 0; k<i; ++k){
    			if(av[i][k].empty()||(mask&(1<<k))==0)continue;
    			for(int o:av[i][k]){
    				if(mask&o){
    					st = 1;
    					break;
					}
				}
				if(st)break;
			}
			if(!st)continue;
//			cout<<i<<' '<<mask<<' ';
//			rep(k,0,i)cout<<((mask&(1<<k)) ? 1 : 0); cout<<endl;
			msk = mask|uj;
			if(__builtin_popcount(mask)<8)dp[nw][msk] = 1;
			for(int k = 1; k<uj; k<<=1){
				if(msk&k)dp[nw][msk^k] = 1;
			}
		}
		memset(dp[ls],0,sizeof dp[ls]);
		ls^=1, nw^=1;
	}
	ans = n+1;
	rep(mask,1,8388607){
		if(dp[ls][mask])ans = min(ans,__builtin_popcount(mask));
	}
	cout<<ans<<endl;
    return 0;
}