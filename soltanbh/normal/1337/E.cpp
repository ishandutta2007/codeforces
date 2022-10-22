#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3005,mod=998244353;
int n,m,p,dp[N][N],ans;
string s,t;

int main(){
	cin>>s>>t;
	n=s.size();
	m=t.size();
	s=' '+s;
	n++;
	f(i,0,m+1) dp[0][i]=1;
	f(i,1,n){
		f(j,0,m){
			if(s[i]==t[j]) dp[i][j]=dp[i-1][j+1]; //ops(1); }
			if(i+j>m || s[i]==t[i+j-1]) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;// ops(2);}
		}
		dp[i][m]=(dp[i-1][m]*2ll)%mod;
		if(i>=m) ans=(ans+dp[i][0])%mod;
	}
	cout<<ans;
}