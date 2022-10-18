#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int N = 3000 + 11;
pair<int,int> a[N];
int d[N],dp[N][N],pos[N][N],ans[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].ff;
        a[i].ss=i;
    }
    sort(a+1,a+n+1);
    a[0].ff=0;
    for (int i=1; i<=n; i++)
        d[i]=a[i].ff-a[i-1].ff;

    int a1=-1,a2=-1,a3=-1;
    int res1=-1,res2=-1,res3=-1;

    for (int i=1; i<=n; i++)
    {
        dp[i][i]=d[i];
        pos[i][i]=i;
        for (int j=i+1; j<=n; j++)
        {
            if (d[j]>dp[i][j-1]) {dp[i][j]=d[j]; pos[i][j]=j;}
            else {dp[i][j]=dp[i][j-1]; pos[i][j]=pos[i][j-1];}
        }
    }

    for (int i=3; i<=n; i++)
    for (int j=2; j<i; j++)
    {
        int kol1=n-i+1;
        int kol2=i-j;
        if (min(kol1,kol2)*2>=max(kol1,kol2))
        {
            int kolmini=(max(kol1,kol2)+1)/2;
            int kolmaxi=(min(kol1,kol2))*2;
            int d1=max(1,j-kolmaxi),d2=j-kolmini;
            if (d1<=d2)
            {
                int dp1=d[i];
                int dp2=d[j];
                int dp3=dp[d1][d2];
                int k=pos[d1][d2];
                if (dp1>res1||(dp1==res1&&dp2>res2)||(dp1==res1&&dp2==res2&&dp3>res3))
                {
                    res1=dp1;
                    res2=dp2;
                    res3=dp3;
                    a1=k;
                    a2=j;
                    a3=i;
                }
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        ans[a[i].ss]=-1;
        if (i>=a1) ans[a[i].ss]=3;
        if (i>=a2) ans[a[i].ss]=2;
        if (i>=a3) ans[a[i].ss]=1;
    }
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}