#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
string s;
int sol(int l,int r)
{
    if (l==r) return 1;
    if (l>r) return 0;
    if (dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=min(sol(l+1,r)+1,sol(l,r-1)+1);
    if (s[l]==s[r])dp[l][r]=min(dp[l][r],sol(l+1,r-1)+1);
    for (int i=l+1;i<=r;i++)
        if (s[i]==s[l])
            dp[l][r]=min(dp[l][r],sol(l+1,i-1)+sol(i,r));
    return dp[l][r];
}
int main()
{
    int n;
    cin>>n;
    cin>>s;
    string t="";
    for (auto x:s)
    {
        if (t.size() && t[t.size()-1]==x)continue;
        t+=x;
    }
    s=t;
    memset(dp,-1,sizeof(dp));
    cout<<sol(0,t.size()-1)<<endl;
}