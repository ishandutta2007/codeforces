#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
const int N = 1000 + 11;

char a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    {
        cin>>a[i][j];
        if (a[i][j]=='.') a[i][j]='D';
        if (a[i][j]=='S'&&a[i-1][j]=='W') {cout<<"No"<<endl; return 0;}
        if (a[i][j]=='S'&&a[i][j-1]=='W') {cout<<"No"<<endl; return 0;}
        if (a[i][j]=='W'&&a[i-1][j]=='S') {cout<<"No"<<endl; return 0;}
        if (a[i][j]=='W'&&a[i][j-1]=='S') {cout<<"No"<<endl; return 0;}
    }
    cout<<"Yes"<<endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            cout<<a[i][j];
        cout<<endl;
    }
}