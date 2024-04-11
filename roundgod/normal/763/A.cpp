/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 15:03:07
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
int n,k,a[MAXN];
vector<int> G[MAXN];
int cnt[MAXN],res;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)G[i].size();j++)
        {
            int u=i,v=G[i][j];
            if(a[u]==a[v]) continue;
            cnt[u]++;cnt[v]++;res++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==res)
        {
            puts("YES");
            printf("%d\n",i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}