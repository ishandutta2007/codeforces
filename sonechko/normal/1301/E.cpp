#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 500 + 11;

int s[5][N][N];
int a[N][N];
int mx[N][N];
int n,m;
int d[11][11][N][N];

int sum(int l1, int r1, int l2, int r2, int p)
{
    return s[p][l2][r2]-s[p][l1-1][r2]-s[p][l2][r1-1]+s[p][l1-1][r1-1];
}

int get(int l1, int r1, int l2, int r2)
{
    if (sum(l1,r1,l2,r2,1)==(r2-r1+1)*(l2-l1+1)) return 1;
    if (sum(l1,r1,l2,r2,2)==(r2-r1+1)*(l2-l1+1)) return 2;
    if (sum(l1,r1,l2,r2,3)==(r2-r1+1)*(l2-l1+1)) return 3;
    if (sum(l1,r1,l2,r2,4)==(r2-r1+1)*(l2-l1+1)) return 4;
    return -1;
}

bool good(int l, int r, int x)
{
    if (x==0) return 1;
    if (get(l-x+1,r-x+1,l,r)!=1) return 0;
    if (get(l-x+1,r+1,l,r+x)!=2) return 0;
    if (get(l+1,r-x+1,l+x,r)!=3) return 0;
    if (get(l+1,r+1,l+x,r+x)!=4) return 0;
    return 1;
}

int get_max(int l1, int r1, int l2, int r2)
{
    if (l1>l2||r1>r2) return 0;
    int d1=0,d2=0;
    for (int i=1; i<11; i++)
    {
        if ((1<<i)<=l2-l1+1) d1=i;
        if ((1<<i)<=r2-r1+1) d2=i;
    }
    return max({
                    d[d1][d2][l1][r1],
                    d[d1][d2][l2-(1<<d1)+1][r1],
                    d[d1][d2][l1][r2-(1<<d2)+1],
                    d[d1][d2][l2-(1<<d1)+1][r2-(1<<d2)+1]
               });
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>n>>m>>q;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char c;
        cin>>c;
        if (c=='R') a[i][j]=1; else
        if (c=='G') a[i][j]=2; else
        if (c=='Y') a[i][j]=3; else a[i][j]=4;
        for (int p=1; p<=4; p++)
            s[p][i][j]=s[p][i-1][j]+s[p][i][j-1]-s[p][i-1][j-1];
        s[a[i][j]][i][j]++;
    }

    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        mx[i][j]=0;
        int l=0,r=min({i,j,n-i,m-j});
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (good(i,j,mid)) l=mid; else r=mid;
        }
        if (good(i,j,r)) mx[i][j]=r; else mx[i][j]=l;
    }
    for (int i=n; i>=1; i--)
    for (int j=m; j>=1; j--)
    {
        for (int p1=0; p1<11; p1++)
        for (int p2=0; p2<11; p2++)
        {
            if (p1==0&&p2==0) d[p1][p2][i][j]=mx[i][j]; else
            if (p2>0&&j+(1<<(p2-1))<=m) d[p1][p2][i][j]=max(
                                           d[p1][p2-1][i][j],
                                           d[p1][p2-1][i][j+(1<<(p2-1))]); else
            if (p1>0&&i+(1<<(p1-1))<=n) d[p1][p2][i][j]=max(
                                  d[p1-1][p2][i][j],
                                  d[p1-1][p2][i+(1<<(p1-1))][j]);
        }
    }
    while (q--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int l=1,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (get_max(l1+mid-1,r1+mid-1,l2-mid,r2-mid)>=mid) l=mid;
            else r=mid;
        }
        if (get_max(l1+r-1,r1+r-1,l2-r,r2-r)>=r) cout<<(r*2)*(r*2)<<"\n"; else
        if (get_max(l1+l-1,r1+l-1,l2-l,r2-l)>=l) cout<<(l*2)*(l*2)<<"\n"; else
        cout<<0<<"\n";
    }
}