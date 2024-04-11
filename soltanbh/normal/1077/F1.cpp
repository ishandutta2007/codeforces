#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n,k,x,dp[202][202],a[209],mx;
int main(){
	cin>>n>>k>>x;
	if(n/k>x){cout<<-1;return 0;}
	f(i,0,n) cin>>a[i];
	f(i,0,n){
		f(j,1,x+1){
			if(i<k) dp[i][j]=a[i]; 
			f(l,max(i-k,(ll)0),i)
				dp[i][j]=max(dp[i][j],(dp[l][j-1]+a[i])*(dp[l][j-1]!=0));
		}
	}
	f(i,n-k,n) mx=max(mx,dp[i][x]);
	cout<<mx;
}