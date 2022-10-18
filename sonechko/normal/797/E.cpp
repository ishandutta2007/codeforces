#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 17;
int a[N],dp[N][301];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int mm=300;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=n; i>=1; i--)
        for (int k=1; k<=mm; k++)
        if (i+a[i]+k>n) dp[i][k]=1; else
        dp[i][k]=dp[i+a[i]+k][k]+1;
    int m;
    cin>>m;
    for (int ij=1; ij<=m; ij++)
    {
        int l,r;
        cin>>l>>r;
        if (r<=mm) cout<<dp[l][r]<<"\n"; else
        {
            int kol=0;
            while (l<=n)
            {
                kol++;
                l=l+a[l]+r;
            }
            cout<<kol<<"\n";
        }
    }
}