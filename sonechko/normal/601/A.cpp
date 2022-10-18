#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 400 + 11;
int a[N][N],use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        a[l][r]=1;
        a[r][l]=1;
    }
    if (a[1][n]==1)
    {
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        if (i!=j&&a[i][j]==0) a[i][j]=1; else a[i][j]=0;
    }
    vector<int> v,w;
    v.pb(1);
    w.pb(0);
    int k=0;
    use[1]=1;
    while (k<v.size())
    {
        int l=v[k],dist=w[k];
        k++;
        if (l==n) {cout<<dist<<endl; return 0;}
        for (int i=1; i<=n; i++)
            if (a[l][i]==1&&use[i]==0) {use[i]=1; v.pb(i); w.pb(dist+1);}
    }
    cout<<-1<<endl;
}