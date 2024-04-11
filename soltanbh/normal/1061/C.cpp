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

const int N=5e5+99,mod=1e9+7;

int n,t,ans,a[N],dp[N];

int main(){
	cin>>n;dp[0]=1;
	f(i,1,n+1){
		cin>>a[i];
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0)
				if(j*j!=a[i] && a[i]/j<N)
					dp[a[i]/j]=(dp[a[i]/j]+dp[a[i]/j-1])%mod;
		for(int j=sqrt(a[i]);j;j--)
			if(a[i]%j==0)
				dp[j]=(dp[j]+dp[j-1])%mod;
	}
	f(i,1,n+1) ans=(ans+dp[i])%mod;
	cout<<ans;
}