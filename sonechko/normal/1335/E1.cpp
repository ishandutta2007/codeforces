#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

int a[N];
int kk[N][202];

void up()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        for (int j=1; j<=200; j++)
            kk[i][j]=kk[i-1][j];
        kk[i][a[i]]++;
        ans=max(ans,kk[i][a[i]]);
    }
    for (int i=1; i<=n; i++)
    {
        int t=a[i];
        int ks=kk[i][t];
        int l=1,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (kk[n][t]-kk[mid-1][t]>=ks) l=mid; else r=mid;
        }
        int pos2=0;
        if (kk[n][t]-kk[r-1][t]>=ks) pos2=r; else pos2=l;
        if (pos2<=i) continue;
        int kol=0;
        for (int j=1; j<=200; j++)
            kol=max(kol,kk[pos2-1][j]-kk[i][j]);
        ans=max(ans,ks*2+kol);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}