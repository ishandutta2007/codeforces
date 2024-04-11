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
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=998244353;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,x[105],m,y[105],dp[105][105];

int f(int a,int b){
	if(a>n||b>m)return 0;
	if(dp[a][b]!=-1)return dp[a][b];
	if(abs(x[a]-y[b])<2)return dp[a][b] = max(max(f(a+1,b),f(a,b+1)),f(a+1,b+1)+1);
	return dp[a][b] = max(f(a+1,b),f(a,b+1));
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,12)cin>>x[i], x[i]*=-1;
    sort(x+1,x+1+12);
    if(n==0)return cout<<0,0;
    rep(i,1,12){
    	n+=x[i];
    	if(n<1)return cout<<i,0;
	}
	cout<<-1;
    return 0;
}