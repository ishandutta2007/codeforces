#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define int long long
#define ll long long
#define sqr(a) ((a)*(a))
#define ld long double
const int N = 1e3 + 11;
int a[N][N];
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (a[i][j]==0&&m!=0)
    {
        if (m==1&&i==j) {a[i][j]=1;m=0;} else
        if (m!=1)
        {
            a[i][j]=1;
            a[j][i]=1;
            if (i==j) m--; else m-=2;
        }
    }
    if (m!=0) {cout<<"-1"<<endl; return 0;}
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}