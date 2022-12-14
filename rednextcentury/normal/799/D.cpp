#include<bits/stdc++.h>
using namespace std;
long long c[1000000];
long long h,w,n;
int dp[40][200000];
int DP(int i,long long a,long long b)
{
	if (max(a,b)>=max(h,w) && min(a,b)>=min(h,w))
		return i;
	if (i==38)
		return 1000000000;
	if (a>=100000)a=100000;
	if (b>=100000)b=100000;
	if (dp[i][a]!=-1)
		return dp[i][a];
	return dp[i][a]=min(DP(i+1,a*c[i],b),DP(i+1,a,b*c[i]));
}
long long a,b;
void solve()
{
    memset(dp,-1,sizeof(dp));
    sort(c,c+n);
    reverse(c,c+n);
    int sol=DP(0,a,b);
    if (sol>50)
        sol=-1;
    cout<<sol<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>h>>w>>a>>b>>n;
    for (int i=0;i<n;i++)
        cin>>c[i];
    solve();
}