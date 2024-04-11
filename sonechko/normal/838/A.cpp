#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back


const int N = 5000 + 11;


int b[N][N],a[N][N];


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
        if (ch=='1') a[i][j]=1;
    }
    for (int i=1; i<=5000; i++)
    for (int j=1; j<=5000; j++)
    b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+a[i][j];
    int res=5000*5000;
    for (int k=2; k<=max(n,m); k++)
    {
        int ans=0;
        for (int i=k; i<=5000; i+=k)
        for (int j=k; j<=5000; j+=k)
        {
            int l=i-k+1;
            int r=j-k+1;
            int ss=b[i][j]-b[i][r-1]-b[l-1][j]+b[l-1][r-1];
            ans+=min(ss,k*k-ss);
        }
        res=min(res,ans);
    }
    cout<<res<<endl;
}