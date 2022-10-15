/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-29 23:32:11
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,s,a[MAXN];
vector<int> G[MAXN];
vector<int> init[MAXK];
int dis[MAXK][MAXN];
bool used[MAXN];
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        init[a[i]].push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    queue<P> que;
    for(int i=1;i<=k;i++)
    {
        while(que.size()) que.pop();
        memset(used,false,sizeof(used));
        fill(dis[i]+1,dis[i]+n+1,INF);
        for(int j=0;j<init[i].size();j++)
        {
            int v=init[i][j];
            dis[i][v]=0;
            que.push(P(v,0));
            used[v]=true;
        }
        while(que.size())
        {
            P p=que.front();
            que.pop();
            int v=p.F,d=p.S;
            for(int j=0;j<G[v].size();j++)
            {
                int to=G[v][j];
                if(!used[to]&&dis[i][to]>d+1)
                {
                    dis[i][to]=d+1;
                    used[to]=true;
                    que.push(P(to,d+1));
                }
            }
        }
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        v.clear();
        for(int j=1;j<=k;j++)
            v.push_back(dis[j][i]);
        sort(v.begin(),v.end());
        int sum=0;
        for(int j=0;j<s;j++)
            sum+=v[j];
        printf("%d ",sum);
    }
    return 0;
}