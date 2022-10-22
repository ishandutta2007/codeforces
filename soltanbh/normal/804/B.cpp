#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,mod=1e9+7;

int n,t,ans;
ll dp[N];
string s;

void calc(){
	dp[1]=1;
	f(i,2,N)
		dp[i]=(dp[i-1]*2ll+1ll)%mod;
}

int main(){
	calc();
	cin>>s;
	n=s.size();
	f(i,0,n){
		t+=(s[i]=='a');
		if(s[i]=='b')
			ans=(ans+dp[t])%mod;
	}
	cout<<ans;
}