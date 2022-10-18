#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 100 + 11;


char a[N][N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ks1=1,ks2=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cin>>a[i][j];
        if (i==1)
        {
            int kol1=1,kol2=0,kol3=0,p=0;
            for (int j=2; j<=m; j++)
            if (a[i][j]==a[i][j-1]) kol1++; else {p=j; break;}
            if (p<=m) kol2=1;
            for (int j=p+1; j<=m; j++)
            if (a[i][j]==a[i][j-1]) kol2++; else {p=j; break;}
            if (p<=m) {if (a[i][1]==a[i][p]) ks1=0; kol3=1;}
            for (int j=p+1; j<=m; j++)
            if (a[i][j]==a[i][j-1]) kol3++; else {ks1=0; break;}
            if (kol1+kol2+kol3>m||kol1!=kol2||kol2!=kol3||kol1!=kol3) ks1=0;
        } else
        {
            for (int j=1; j<=m; j++)
                if (a[i][j]!=a[i-1][j]) ks1=0;
        }
    }
    if (ks1==1) {cout<<"YES"<<endl; return 0;}
    for (int j=1; j<=m; j++)
    {
        if (j==1)
        {
            int kol1=1,kol2=0,kol3=0,p=0;
            for (int i=2; i<=n; i++)
            if (a[i][j]==a[i-1][j]) kol1++; else {p=i; break;}
            if (p<=n) kol2=1;
            for (int i=p+1; i<=n; i++)
            if (a[i][j]==a[i-1][j]) kol2++; else {p=i; break;}
            if (p<=n) {if (a[1][j]==a[p][j]) ks2=0;kol3=1;}
            for (int i=p+1; i<=n; i++)
            if (a[i][j]==a[1][j]) {ks2=0; break;} else
            if (a[i][j]==a[i-1][j]) kol3++; else {ks2=0; break;}
            if (kol1+kol2+kol3>n||kol1!=kol2||kol2!=kol3||kol1!=kol3) ks2=0;
        } else
        {
            for (int i=1; i<=n; i++)
                if (a[i][j]!=a[i][j-1]) ks2=0;
        }
    }
    if (ks2==1) {cout<<"YES"<<endl; return 0;}
    cout<<"NO"<<endl;
}