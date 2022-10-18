#include<bits/stdc++.h>
using namespace std;
const int N = 1e5
 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
int a[N],dp[N];
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l1=0,l2=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        while (a[l1+1]+90<=a[i])
        l1++;
        while (a[l2+1]+1440<=a[i])
        l2++;
        dp[i]=min(dp[i-1]+20,min(dp[l1]+50,dp[l2]+120));
        cout<<dp[i]-ans<<endl;
        ans=dp[i];
    }
}