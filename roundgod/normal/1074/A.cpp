/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 22:08:47
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> v;
int d[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        v.push_back(x);
    }
    v.push_back(0);v.push_back(INF);
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        int x1,x2,y;
        scanf("%d%d%d",&x1,&x2,&y);
        if(x1!=1) continue;
        int r=upper_bound(v.begin(),v.end(),x2)-v.begin()-1;
        d[1]++;d[r+1]--;
    }
    for(int i=1;i<=n+1;i++) d[i]+=d[i-1];
    int ans=INF;
    for(int i=1;i<=n+1;i++) ans=min(ans,i-1+d[i]);
    printf("%d\n",ans);
    return 0;
}