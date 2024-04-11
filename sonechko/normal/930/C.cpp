#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;

int a[N],r1[N],r2[N];

int dp[N],res1[N],res2[N];


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m>>n;
    for (int i=1; i<=m; i++)
    {
              int l,r;
              cin>>l>>r;
              a[l]++;
              a[r+1]--;
    }
    for (int i=1; i<=n; i++)
    a[i]+=a[i-1];
    if (n==1) {cout<<0<<endl; return 0;}
    int kol=1;
    dp[1]=a[1];
    res1[1]=1;
    for (int i=2; i<=n; i++)
    {
              int l=1,r=kol;
              while (r-l>1)
              {
                        int mid=(l+r)/2;
                        if (dp[mid]>a[i]) r=mid; else l=mid;
              }
              if (dp[l]>a[i]) {dp[l]=a[i]; res1[i]=l;} else
              if (dp[r]>a[i]) {dp[r]=a[i]; res1[i]=r;} else
              {
                        kol++;
                        dp[kol]=a[i];
                        res1[i]=kol;
              }
    }
    kol=1;
    dp[1]=a[n];
    res2[n]=1;
    int ans=0;
    for (int i=n-1; i>=1; i--)
    {
              int l=1,r=kol;
              while (r-l>1)
              {
                        int mid=(l+r)/2;
                        if (dp[mid]>a[i]) r=mid; else l=mid;
              }
              if (dp[l]>a[i]) {dp[l]=a[i]; res2[i]=l;} else
              if (dp[r]>a[i]) {dp[r]=a[i]; res2[i]=r;} else
              {
                        kol++;
                        dp[kol]=a[i];
                        res2[i]=kol;
              }
              ans=max(ans,res1[i]+res2[i]-1);
    }
    cout<<ans<<endl;
}