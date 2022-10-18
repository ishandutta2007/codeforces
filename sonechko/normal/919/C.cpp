#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
const ll N = 2000 + 11;

char a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int kol=0;
        for (int j=1; j<=m; j++)
        {
            if (a[i][j]=='.') kol++; else kol=0;
            if (kol>=k) ans++;
        }
    }
    for (int j=1; j<=m; j++)
    {
        int kol=0;
        for (int i=1; i<=n; i++)
        {
            if (a[i][j]=='.') kol++; else kol=0;
            if (kol>=k) ans++;
        }
    }
    if (k==1) cout<<ans/2<<endl;
    else cout<<ans<<endl;
}