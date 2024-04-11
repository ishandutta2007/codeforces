#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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

int m;
string s;
bool x[11];
short int dp[1001][11][11];

bool f(int rem,int ls,int df){
	if(rem==0)return dp[rem][ls][df] = 1;
	if(dp[rem][ls][df]!=-1)return dp[rem][ls][df];
	bool res = 0;
	rep(i,df+1,10){
		if(!x[i])continue;
		if(i==ls)continue;
		res|=f(rem-1,i,i-df);
	}
	return dp[rem][ls][df] = res;
}

void bt(int rem,int ls,int df){
	if(rem==0)return;
	rep(i,df+1,10){
		if(!x[i])continue;
		if(i==ls)continue;
		if(dp[rem-1][i][i-df]){
			cout<<i<<' ';
			bt(rem-1,i,i-df);
			return;
		}
	}
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>m;
    rep(i,0,9)if(s[i]=='1')x[i+1] = 1;
	memset(dp,-1,sizeof dp);
	if(!f(m,0,0))return cout<<"NO",0;
	cout<<"YES\n";
	bt(m,0,0);
    return 0;
}