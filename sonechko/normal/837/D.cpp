#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 200 + 11;


int dp1[202][5001],dp2[202][5001];
int kol1[N],kol2[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        {
            ll p;
            cin>>p;
            while (p%2==0)
            {
                p/=2;
                kol1[i]++;
            }
            while (p%5==0)
            {
                p/=5;
                kol2[i]++;
            }
        }
    n++;
    int maxk=5000;
    for (int j=0; j<=m; j++)
    for (int k=1; k<=maxk; k++)
        dp1[j][k]=-1;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=m; j++)
        for (int k=1; k<=maxk; k++)
        dp2[j][k]=-1;

        for (int j=0; j<=min(m,i); j++)
            for (int k=0; k<=maxk; k++)
                if (dp1[j][k]!=-1)
        {
            dp2[j][k]=max(dp2[j][k],dp1[j][k]);
            dp2[j+1][k+kol2[i+1]]=max(dp2[j+1][k+kol2[i+1]],dp1[j][k]+kol1[i+1]);
            if (j==m) ans=max(ans,min(dp1[j][k],k));
        }
        for (int j=0; j<=m; j++)
        for (int k=0; k<=maxk; k++)
        dp1[j][k]=dp2[j][k];
    }

    cout<<ans<<endl;
}