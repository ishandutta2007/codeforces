#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll dp[200009],t,n,p,k,a[200009],p1,ans;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>p>>k;
		f(i,1,n+1) cin>>a[i];
		sort(a+1,a+n+1);
		p1=0;ans=0;
		dp[0]=p;
		f(i,1,n+1){
			dp[i]=dp[i-1]-a[i];
			if(i>=k)
				dp[i]=max(dp[i],dp[i-k]-a[i]);
			if(dp[i]>=0){
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
}