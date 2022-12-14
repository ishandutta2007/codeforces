#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[5001][5001];
int sol(int l,int r)
{
    if (l>r)return 0;
    if (l==r)return 0;
    if (dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=max(sol(l+1,r),sol(l,r-1));
    if (v[l]==v[r])dp[l][r]=max(dp[l][r],sol(l+1,r-1)+1);
    return dp[l][r];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> in(n);
    for (int i=0;i<n;i++)
    {
        cin>>in[i];
        if (i==0 || in[i]!=in[i-1])
            v.push_back(in[i]);
    }
    int ret=v.size()-1;
    ret-=sol(0,v.size()-1);
    cout<<ret<<endl;
}