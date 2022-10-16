#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,x[MAX],dp[MAX][2];
char c[MAX];

int f(int nw,bool st){
	if(!nw)return 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	if(st)return dp[nw][st] = f(nw-1,st)+x[nw];
	if(c[nw])return dp[nw][st] = max(f(nw-1,0)+x[nw],f(nw-1,1));
	return dp[nw][st] = f(nw-1,0);
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>c[i], c[i]-='0';
    memset(dp,-1,sizeof dp);
    cout<<f(n,0);
    return 0;
}