#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int vis[1000000];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int l=1;
    int cnt=0;
    int ret=0;
    for (int r=1;r<=n;r++)
    {
        if (a[r]==a[r-1])l=r;
        ret=max(r-l+1,ret);
    }
    cout<<ret<<endl;
}