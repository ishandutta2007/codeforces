#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int res=1e9;
    for (int i=1; i<=n; i++)
    {
        dp[i]=1e9;
        for (int j=1; j<i; j++)
        if (a[j]<a[i]&&dp[i]>b[i]+b[j]) dp[i]=b[i]+b[j];
        for (int j=1; j<i; j++)
            if (a[j]<a[i]&&res>dp[j]+b[i]) res=dp[j]+b[i];
    }
    if (res==1000000000) cout<<-1<<"\n"; else cout<<res<<endl;
}