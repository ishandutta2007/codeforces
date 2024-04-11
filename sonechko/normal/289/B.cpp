#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const ll N = 5000000 + 11;
ll a[N],dp[N];
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[(i-1)*m+j];
    n=n*m;
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    if (a[i]%k!=a[1]%k) {cout<<"-1"<<endl; return 0;}
    int ans=1000000000;
    for (int j=0; j<=10000; j++)
    if (j%k==a[1]%k)
    {
        int res=0;
        for (int i=1; i<=n; i++)
            res+=abs(j-a[i])/k;
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}