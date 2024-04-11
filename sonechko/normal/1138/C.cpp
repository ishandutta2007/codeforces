#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 1000 + 11;
const int MOD = 1e9 + 7;

pair<int,int> b[N];
int a[N][N];
int mini1[N][N],bigger1[N][N],mini2[N][N],bigger2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            b[j]=mp(a[i][j],j);
        sort(b+1,b+m+1);
        int kol=0;
        for (int j=1; j<=m; j++)
        {
            if (b[j].ff!=b[j-1].ff) kol++;
            mini1[i][b[j].ss]=kol;
        }
        kol=0;
        b[m+1].ff=0;
        for (int j=m; j>=1; j--)
        {
            if (b[j].ff!=b[j+1].ff) kol++;
            bigger1[i][b[j].ss]=kol-1;
        }
    }
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n; i++)
            b[i]=mp(a[i][j],i);
        sort(b+1,b+n+1);
        int kol=0;
        for (int i=1; i<=n; i++)
        {
            if (b[i].ff!=b[i-1].ff) kol++;
            mini2[b[i].ss][j]=kol;
        }
        kol=0;
        b[n+1].ff=0;
        for (int i=n; i>=1; i--)
        {
            if (b[i].ff!=b[i+1].ff) kol++;
            bigger2[b[i].ss][j]=kol-1;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            int x=max(mini1[i][j],mini2[i][j]);
            cout<<x+max(bigger1[i][j],bigger2[i][j])<<" ";
        }
        cout<<endl;
    }
}