#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include <climits>
using namespace std;
typedef long long ll;
const int maxn= 1e6+5;
const int inf = 0x3f3f3f3f;
int n,m,k;
int t[1000000+10];
int main()
{
    cin>>n>>m;
    int a[n+2][m+2];
    int f[n+2][m+2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>=a[i-1][j])f[i][j]=f[i-1][j]+1;
            else f[i][j]=1;
            t[i]=max(t[i],f[i][j]);
        }
    }
    cin>>k;
    int xx,yy;
    while(k--)
    {
        scanf("%d %d",&xx,&yy);
        if(t[yy]>=yy-xx+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}