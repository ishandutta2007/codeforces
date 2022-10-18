
#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
char a[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        cin>>a[i][j];
    int p=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        if (a[i][j]=='X'&&a[i-1][j]!='1'&&p==0)
    {
        p=1;
        for (int r=j; r<=m; r++)
            if (a[i][r]=='.') break; else a[i][r]='1';
    } else
    if (a[i][j]=='X'&&a[i-1][j]=='1'&&a[i-1][j-1]=='1'&&a[i][j-1]!='1') {cout<<"NO"<<endl; return 0;} else
    if (a[i][j]=='X'&&a[i-1][j]=='1') a[i][j]='1'; else
    if (a[i][j]=='X'&&a[i-1][j]!='1') {cout<<"NO"<<endl; return 0;} else
    if (a[i-1][j]=='1'&&a[i][j-1]=='1') {cout<<"NO"<<endl; return 0;}
    cout<<"YES"<<endl;
}