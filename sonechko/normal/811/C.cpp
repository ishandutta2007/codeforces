#include<bits/stdc++.h>
using namespace std;
const int N = 5000 + 11;
int a[N],b[N][N],c[N][N],use[N],las[N],last[N],fir[N],first[N],dp[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    int kol=0;
    for (int i=1; i<=n; i++)
    {
        if (use[a[i]]==0) fir[a[i]]=i;
        use[a[i]]=1;
        las[a[i]]=i;
    }
    for (int i=1; i<=n; i++)
    {
        int maxi=i;
        int xr=0;
        for (int j=i; j<=n; j++)
        {
            if (fir[a[j]]<i) break;
            if (fir[a[j]]==j) xr^=a[j];
            maxi=max(maxi,las[a[j]]);
            if (maxi==j) {b[i][j]=1; c[i][j]=xr;}
        }
    }
    for (int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1];
        for (int j=1; j<=i; j++)
        if (b[j][i]==1) dp[i]=max(dp[i],dp[j-1]+c[j][i]);
    }
    cout<<dp[n]<<endl;
}