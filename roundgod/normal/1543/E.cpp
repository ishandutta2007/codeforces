#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> P;
int t,n,tot;
vector<int> G[(1<<16)];
int perm[(1<<16)];
int inv[(1<<16)];
int color[(1<<16)];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<(1<<n);i++) G[i].clear();
        for(int i=0;i<n*(1<<(n-1));i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        tot=0;
        queue<int> que;
        que.push(0);
        memset(perm,-1,sizeof(perm));
        perm[0]=0;
        while(que.size())
        {
            int v=que.front(); que.pop();
            int mask=0;
            if(perm[v]==-2)
            {
                for(auto to:G[v])
                {
                    if(perm[to]>=0) mask|=perm[to];
                }
                perm[v]=mask;
            }
            if(v==0)
            {
                for(auto to:G[v])
                {
                    perm[to]=(1<<tot);
                    tot++;
                    que.push(to);
                }
            }
            else
            {
                for(auto to:G[v])
                {
                    if(perm[to]==-1)
                    {
                        perm[to]=-2;
                        que.push(to);
                    }
                }
            }
        }
        for(int i=0;i<(1<<n);i++) inv[perm[i]]=i;
        for(int i=0;i<(1<<n);i++) printf("%d%c",inv[i],i==((1<<n)-1)?'\n':' ');
        if(n==1) puts("0 0");
        else if(n==2||n==4||n==8||n==16)
        {
            for(int i=0;i<(1<<n);i++) 
            {
                int c=0;
                for(int j=0;j<n;j++)if(perm[i]&(1<<j)) c^=j;
                printf("%d ",c);
            }
            puts("");
        }
        else
        {
            puts("-1");
        }
    }
}