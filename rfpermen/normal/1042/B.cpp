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
#define piii pair<pii,int>
#define piiii pair<piii,pii>
#define endl "\n"
const int MAX=3e4+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,dp[1005][7],res;
pii x[1005];
string s;

int f(int pos,int mask){
	if(mask==7)return 0;
	if(pos>n)return 300001;
	if(dp[pos][mask]!=-1)return dp[pos][mask];
	return dp[pos][mask] = min(f(pos+1,mask), f(pos+1,mask|x[pos].se)+x[pos].fi);
}

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i].fi>>s;
    	for(auto j:s)x[i].se|=(1<<(j-'A'));
	}
	memset(dp,-1,sizeof dp);
	if(f(1,0)<=300000)cout<<f(1,0)<<endl;
	else cout<<"-1\n";
    return 0;
}