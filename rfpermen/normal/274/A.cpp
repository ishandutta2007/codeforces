#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,k,x,ans,dp[MAX][2],id,cv[MAX];
bool vis[MAX];
int v[MAX];
map<ll,int> m,hs;

int f(int nw,bool st){
	vis[nw] = 1;
	if(!v[nw])return st ? cv[nw] : 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	if(st)return dp[nw][st] = max(cv[nw]+f(v[nw],0),f(v[nw],1));
	return dp[nw][st] = f(v[nw],1);
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(k==1)return cout<<n,0;
    rep(i,1,n)cin>>x, m[x]++;
    for(auto i:m)hs[i.fi] = ++id, cv[id] = i.se;
    for(auto i:m){
    	if(!m.count(i.fi*k))continue;
    	v[hs[i.fi]] = hs[i.fi*k];
	}
	memset(dp,-1,sizeof dp);
	rep(i,1,id){
		if(vis[i])continue;
		ans+=f(i,1);
	}
	cout<<ans<<endl;
    return 0;
}