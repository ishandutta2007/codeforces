/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 17:54:46
 ************************************************************************/

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
int deg[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        deg[v]++;deg[u]++;
    }
    int ans=-1;
    vector<int> save;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1) save.push_back(i);
        if(deg[i]>2)
        {
            if(ans!=-1)
            {
                puts("No");
                return 0;
            }
            ans=i;
        }
    }
    puts("Yes");
    if(ans==-1)
    {
        puts("1");
        printf("%d %d\n",save[0],save[1]);
        return 0;
    }
    printf("%d\n",save.size());
    for(int i=0;i<save.size();i++)
        printf("%d %d\n",save[i],ans);
    return 0;
}