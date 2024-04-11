#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
int a[N],dp[N];
int get(int l, int r)
{
    if (l%2==0&&r%2==0) return 0;
    if (l%2==1&&r%2==1) return 1;
    return 2;
}
int main()
{
    int n;
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        k=__gcd(a[i],k);
    }
    if (k>1) {cout<<"YES"<<endl<<0<<endl; return 0;}
    if (a[1]%2==0) dp[1]=0; else dp[1]=n*5;
    for (int i=2; i<=n; i++)
    {
        int p=get(a[i-1],a[i]);
        dp[i]=min(n*5,dp[i-2]+p);
        dp[i]=min(dp[i],get(0,a[i])+dp[i-1]);
    }
    if (dp[n]!=n*5) cout<<"YES"<<endl<<dp[n]<<endl; else cout<<"NO"<<endl;
}