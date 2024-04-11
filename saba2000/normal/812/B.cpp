#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[33][2];
int a[109][109];
int x[1109],y[1009];
int r=0;
int ch=0;
main()
{int n,m;
cin>>n>>m;
for(int i=0; i<n; i++)
{string s;
cin>>s;
int f=0;
for (int j=0; j<m+2; j++)
if(s[j]=='1') {if(f==0) x[i]=j; y[i]=j; f=1;}
if(f==0) {x[i]=-1; y[i]=-1;}
if(f==0) {i--;n--; if(ch==1) r++;} else ch=1;}
if(n==1) {cout<<y[0]<<endl;return 0;}
else if(n==0) {cout<<0<<endl; return 0;}
dp[n-1][0]=2*y[n-1];
dp[n-1][1]=m+1;
for(int i=n-2; i>=1; i--)
{
        if(x[i]==-1) {
dp[i][0]=min(dp[i+1][1]+m+1,dp[i+1][0]);
dp[i][1]=min(dp[i+1][0]+m+1,dp[i+1][1]);}else{
dp[i][0]= min(dp[i+1][1]+m+1,dp[i+1][0]+2*y[i]);
dp[i][1]=min(dp[i+1][0]+m+1,dp[i+1][1]+2*(m+1-x[i]));
}}
//cout<<dp[1][0]<<" "<<dp[1][1]<<endl;
cout<<min(dp[1][0]+y[0],dp[1][1]+m+1-x[0])+n+r-1<<endl;

}