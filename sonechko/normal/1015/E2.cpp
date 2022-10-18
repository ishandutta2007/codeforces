#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1000 + 11;
const int MOD = 1e9 + 7;

char b[N][N],a[N][N];
int a1[N][N],a2[N][N];
int mx1[N][N],mx2[N][N],mx3[N][N],mx4[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        cin>>a[i][j];
    vector<int> xx,yy,tt;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='*')
    {
        mx1[i][j]=mx1[i-1][j]+1;
        mx2[i][j]=mx2[i][j-1]+1;
    }
    for (int i=n; i>=1; i--)
    for (int j=m; j>=1; j--)
    if (a[i][j]=='*')
    {
        mx3[i][j]=mx3[i+1][j]+1;
        mx4[i][j]=mx4[i][j+1]+1;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        int p=min({mx1[i][j],mx2[i][j],mx3[i][j],mx4[i][j]})-1;
        if (p>0)
        {
            xx.pb(i);
            yy.pb(j);
            tt.pb(p);
            a1[i][j-p]++;
            a1[i][j+p+1]--;
            a2[i-p][j]++;
            a2[i+p+1][j]--;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        a1[i][j]+=a1[i][j-1];
        if (a1[i][j]>0) b[i][j]='*';
        a2[i][j]+=a2[i-1][j];
        if (a2[i][j]>0) b[i][j]='*';
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]=='*'&&b[i][j]!='*')
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<xx.size()<<"\n";
    for (int j=0; j<xx.size(); j++)
        cout<<xx[j]<<" "<<yy[j]<<" "<<tt[j]<<"\n";
}