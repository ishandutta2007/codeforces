#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll dp[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    dp[0]=1;
    bool ok=0;
    for (int i=1;i<s.size();i++) {
        if (s[i]=='w' || s[i]=='m')ok=1;
        dp[i]+=dp[i-1];
        if (s[i]=='u' && s[i-1]=='u')dp[i]+=dp[i-2];
        if (s[i]=='n' && s[i-1]=='n')dp[i]+=dp[i-2];
        dp[i]%=mod;
    }
    if (ok)dp[s.size()-1]=0;
    cout<<dp[s.size()-1]<<endl;
}