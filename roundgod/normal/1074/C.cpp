/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 23:26:20
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int x[MAXN],y[MAXN];
int minx,maxx,miny,maxy;
int main()
{
    scanf("%d",&n);
    minx=miny=INF;maxx=maxy=-INF;
    for(int i=0;i<n;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        minx=min(minx,x[i]);
        maxx=max(maxx,x[i]);
        miny=min(miny,y[i]);
        maxy=max(maxy,y[i]);
    }
    int ans=-INF;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,2*(maxx-x[i])+2*(maxy-y[i]));
        ans=max(ans,2*(maxx-x[i])+2*(y[i]-miny));
        ans=max(ans,2*(x[i]-minx)+2*(maxy-y[i]));
        ans=max(ans,2*(x[i]-minx)+2*(y[i]-miny));
        ans=max(ans,2*(maxx-minx));ans=max(ans,2*(maxy-miny));
    }
    printf("%d%c",ans,n==3?'\n':' ');
    for(int i=4;i<=n;i++) printf("%d%c",2*(maxx-minx)+2*(maxy-miny),i==n?'\n':' ');
    return 0;
}