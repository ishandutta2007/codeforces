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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,x[MAX],dp[MAX][2];
string s[MAX][2];

bool cmp(string a,string b){
return a>=b;
}

ll f(int nw,bool ls){
	if(nw>n)return 0;
	if(dp[nw][ls]!=-1)return dp[nw][ls];
	ll ret = 2e17;
	if(cmp(s[nw][0],s[nw-1][ls]))ret = min(ret,f(nw+1,0));
	if(cmp(s[nw][1],s[nw-1][ls]))ret = min(ret,f(nw+1,1)+x[nw]);
	return dp[nw][ls] = ret;
}

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>s[i][0], s[i][1] = s[i][0], reverse(s[i][1].begin(),s[i][1].end());
    memset(dp,-1,sizeof dp);
    if(f(1,0)>1e17)cout<<-1;
    else cout<<f(1,0);
    return 0;
}