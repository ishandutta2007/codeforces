#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000 + 11;

char a[N][N];

int b[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        int gg=0;
        for (int p=0; p<m; p++)
        if (a[i][j+p]!='.') {gg=1; break;}
        if (gg==0)
        {
            for (int p=0; p<m; p++)
                b[i][j+p]++;
        }
        gg=0;
        for (int p=0; p<m; p++)
        if (a[i+p][j]!='.') {gg=1; break;}
        if (gg==0)
        {
            for (int p=0; p<m; p++)
                b[i+p][j]++;
        }
    }
    int l=1,r=1;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (b[i][j]>b[l][r]) {l=i; r=j;}
    cout<<l<<" "<<r<<endl;
}