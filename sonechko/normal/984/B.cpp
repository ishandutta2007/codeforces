#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair

const int N = 100 + 11;

int a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        char ch;
        cin>>ch;
        if (ch=='*') a[i][j]=-1; else
        if (ch=='.') a[i][j]=0; else a[i][j]=ch-'0';
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    if (a[i][j]!=-1)
    {
        int kk=0;
        for (int p=max(1,i-1); p<=min(n,i+1); p++)
        for (int d=max(1,j-1); d<=min(m,j+1); d++)
        if (a[p][d]==-1) kk++;
        if (kk!=a[i][j]) {cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
}