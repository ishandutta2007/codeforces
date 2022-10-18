#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 50 + 11;
int a[N][N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        int kol1=0,kol2=0;
        for (int j=1; j<=m; j++)
            if (a[i][j]==1) kol1++; else kol2++;
        ll d=1;
        for (int p=1; p<=kol1; p++)
            d*=2;
        ans+=d-1;
        d=1;
        for (int p=1; p<=kol2; p++)
            d*=2;
        ans+=d-1;
        ans-=kol1;
        ans-=kol2;
    }
    for (int j=1; j<=m; j++)
    {
        int kol1=0,kol2=0;
        for (int i=1; i<=n; i++)
            if (a[i][j]==1) kol1++; else kol2++;
        ll d=1;
        for (int p=1; p<=kol1; p++)
            d*=2;
        ans+=d-1;
        d=1;
        for (int p=1; p<=kol2; p++)
            d*=2;
        ans+=d-1;
    }
    cout<<ans<<endl;
}