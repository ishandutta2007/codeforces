#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 1e6 + 11;

int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        int res=0;
        for (int j=1; j<=(int)sqrt(l); j++)
            if (l%j==0)
        {
            if (j!=1) res=max(res,dp[j]);
            if (l/j!=1) res=max(res,dp[l/j]);
        }
        res++;
        for (int j=1; j<=(int)sqrt(l); j++)
        if (l%j==0)
        {
            if (j!=1) dp[j]=max(dp[j],res);
            if (l/j!=1) dp[l/j]=max(res,dp[l/j]);
        }
    }
    int res=1;
    for (int i=1; i<=100000; i++)
        res=max(res,dp[i]);
    cout<<res<<endl;
}