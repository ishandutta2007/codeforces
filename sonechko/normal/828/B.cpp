#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;

char a[N][N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l1,r1,l2,r2;
    l1=0;
    r1=0;
    l2=0;
    r2=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='B')
        {
            if (l1==0) l1=i;
            if (r1==0||r1>j) r1=j;
            l2=i;
            if (j>r2) r2=j;
        }
    }
    int x=max(l2-l1+1,r2-r1+1);
    int ans=0;
    a[0][0]='W';
    for (int i=l1; i<=l2; i++)
    for (int j=r1; j<=r2; j++)
    if (a[i][j]=='W') ans++;
    if (x!=l2-l1+1)
    {
        int d=x-(l2-l1+1);
        if (l1-1+n-l2>=d) cout<<ans+d*x<<endl; else cout<<-1<<endl;
        return 0;
    }
    int d=x-(r2-r1+1);
    if (r1-1+m-r2>=d) cout<<ans+d*x<<endl; else cout<<-1<<endl;
}