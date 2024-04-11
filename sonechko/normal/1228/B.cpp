#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1000 + 11;

int a[N],b[N],c[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        for (int j=1; j<=x; j++)
            c[i][j]=1;
        c[i][x+1]=2;
    }
    for (int j=1; j<=m; j++)
    {
        int y;
        cin>>y;
        for (int i=1; i<=y; i++)
            if (c[i][j]==2) {cout<<0; return 0;} else c[i][j]=1;
        if (y+1<=n&&c[y+1][j]==1) {cout<<0; return 0;}
        c[y+1][j]=2;
    }
    int ans=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (c[i][j]==0) ans=(ans*2ll)%1000000007;
    cout<<ans;
}