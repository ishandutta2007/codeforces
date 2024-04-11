#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=5e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,x[MAX],dp[MAX][2501][2],N;

int f(int idx,int rem,bool st){
	if(rem==0)return 0;
	if(idx>n)return 1000000000;
	if(dp[idx][rem][st]!=-1)return dp[idx][rem][st];
	int a,b;
	if(st)a = max(min(x[idx-2]-1,x[idx-1]) - x[idx] + 1, 0);
	else a = max(x[idx-1] - x[idx] + 1, 0);
	b = max(x[idx+1] - x[idx] + 1, 0);
	return dp[idx][rem][st] = min(f(idx+1,rem,0),f(idx+2,rem-1,1)+a+b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    memset(dp,-1,sizeof dp);
    N = (n+1)/2;
    rep(i,1,N){
    	cout<<f(1,i,0);
    	if(i==N)cout<<endl;
    	else cout<<" ";
	}
    return 0;
}