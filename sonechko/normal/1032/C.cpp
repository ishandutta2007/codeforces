#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

int a[N],dp[N][6];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
    dp[1][5]=1;
    for (int i=1; i<n; i++)
    for (int t=1; t<=5; t++)
    for (int d=1; d<=5; d++)
    if (a[i]<a[i+1]&&t<d&&dp[i][t]!=0) dp[i+1][d]=t; else
    if (a[i]>a[i+1]&&t>d&&dp[i][t]!=0) dp[i+1][d]=t; else
    if (a[i]==a[i+1]&&t!=d&&dp[i][t]!=0) dp[i+1][d]=t;

    for (int ii=1; ii<=5; ii++)
        if (dp[n][ii]!=0)
    {
        vector<int> v;
        int t=ii;
        for (int i=n; i>=1; i--)
        {
            v.pb(t);
            t=dp[i][t];
        }
        for (int i=v.size()-1; i>=0; i--)
            cout<<v[i]<<" ";
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
}