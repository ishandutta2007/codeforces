#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
const int N = 1000 + 11;

bool a[N][N],use[N];
int d1[N],d2[N],n;

void up(int l)
{
    for (int i=0; i<=n; i++)
    {
        d1[i]=1000;
        use[i]=0;
    }
    d1[l]=0;
    for (int d=1; d<=n; d++)
    {
        int x=0;
        for (int i=1; i<=n; i++)
            if (use[i]==0&&d1[i]<d1[x]) x=i;
        use[x]=1;
        for (int i=1; i<=n; i++)
            if (a[x][i]&&d1[i]>d1[x]+1) d1[i]=d1[x]+1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,s,t;
    cin>>n>>m>>s>>t;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        a[l][r]=1;
        a[r][l]=1;
    }
    up(t);
    for (int i=1; i<=n; i++)
        d2[i]=d1[i];
    up(s);
    int ans=0;
    for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    if (a[i][j]!=1&&i!=j&&d1[i]+d2[j]+1>=d1[t]&&d2[i]+d1[j]+1>=d1[t]) ans++;
    cout<<ans<<endl;
}