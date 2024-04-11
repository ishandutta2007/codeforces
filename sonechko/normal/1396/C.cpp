#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

ll r1,r2,r3,d,a[N],dp1[N],dp2[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>r1>>r2>>r3>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    dp1[0]=0;
    dp2[0]=1e18;
    for (int i=1; i<=n; i++)
    {
        ll c1=r1*a[i]+r3;
        ll c2=min(r2,r1*(a[i]+1))+r1;
        c2=min(c2,c1);
        dp1[i]=min(dp1[i-1]+c1,dp2[i-1]+c2+d);
        dp2[i]=dp1[i-1]+c2+d;
    }
    dp1[n]=min(dp1[n],dp2[n-1]+r1*a[n]+r3);
    ll ans=dp1[n];
    ans=min(ans,dp2[n]+d);
    ans+=d*(n-1);
    cout<<ans;
}
/**
 r2     +  -1 -> 
 r1*ai+r3      
 r1*(ai+1)     +  -1 -> 

1. min(r2,r1*(ai+1))+r1  + 
2. r1*ai+r3   

0 1 1 0 1 1 0 0 0 1
1 1 1 0 + 6

**/