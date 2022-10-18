#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 1000 + 11;

int a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    if (x>1&&y!=1) {cout<<"NO"<<endl; return 0;}
    if (x>1&&y==1)
    {
        for (int i=1; i<=n-(x-1); i++)
        for (int j=1; j<=n-(x-1); j++)
        if (i!=j) a[i][j]=1;
    } else
    if (y==1)
    {
        if (n==2||n==3) {cout<<"NO"<<endl; return 0;}
        for (int i=1; i<n; i++)
        {
            a[i][i+1]=1;
            a[i+1][i]=1;
        }
    } else
    {
        for (int j=1; j<=y-1; j++)
        for (int p=1; p<=n; p++)
        if (j!=p) {a[j][p]=1; a[p][j]=1;}
    }
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}