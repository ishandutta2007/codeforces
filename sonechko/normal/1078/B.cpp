#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double

const int N = 100 + 11;

int a[N],kk[N];
int dp1[N][N*N],dp2[N][N*N];

bool kol_sum(int l, int r)
{
    if (dp1[l][r]==1) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        kk[a[i]]++;
    dp1[0][0]=1;
    int t=0;
    for (int i=1; i<=100; i++)
    {
        for (int kol=0; kol<=t; kol++)
        for (int sum=0; sum<=t*100; sum++)
        if (dp1[kol][sum]>0)
        for (int p=0; p<=kk[i]; p++)
        {
            dp2[kol+p][sum+i*p]+=dp1[kol][sum];
            dp2[kol+p][sum+i*p]=min(dp2[kol+p][sum+i*p],10);
        }
        t+=kk[i];
        for (int kol=0; kol<=t; kol++)
        for (int sum=0; sum<=t*100; sum++)
        {
            dp1[kol][sum]=dp2[kol][sum];
            dp2[kol][sum]=0;
        }
    }
    sort(a+1,a+n+1);
    int ans=1;
    if (a[1]==a[n]) {cout<<n<<endl; return 0;}
    for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++)
        if (kol_sum(j-i+1,a[i]*(j-i+1)))
    {
        if (a[i]==a[j]) ans=max(ans,j-i+1);
        if (a[i]==a[j]&&j==n&&a[i-1]==a[1]) ans=n;
        if (a[i]==a[j]&&i==1&&a[j+1]==a[n]) ans=n;
        if (j==n&&a[i-1]==a[1]) ans=max(ans,i);
        if (i==1&&a[j+1]==a[n]) ans=max(ans,n-j);
    }
    cout<<ans<<endl;
}