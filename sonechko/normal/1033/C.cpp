#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

int a[N],b[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    for (int i=n; i>=1; i--)
    {
        int t=b[i];
        dp[t]=0;
        for (int d=i; d<=n; d+=i)
        {
            if (t>=d&&a[t-d]>i&&dp[t-d]==0) dp[t]=1;
            if (t+d<=n&&a[t+d]>i&&dp[t+d]==0) dp[t]=1;
        }
    }
    for (int i=1; i<=n; i++)
        if (dp[i]==0) cout<<"B"; else cout<<"A";
}