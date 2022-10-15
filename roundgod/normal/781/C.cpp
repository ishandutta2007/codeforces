#include<bits/stdc++.h>
#define MAXV 200005
using namespace std;
int n,m,k;
vector<int> G[MAXV];
int vs[MAXV*2-1];
bool used[MAXV];
void dfs(int v,int p,int &t)
{
    vs[t++]=v;
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]!=p&&!used[G[v][i]])
        {
            dfs(G[v][i],v,t);
            vs[t++]=v;
        }
    }
}
void init(int V)
{
    int t=0;
    memset(used,false,sizeof(used));
    dfs(0,-1,t);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    init(n);
    int move=(2*n-1)/k;
    int rem=(2*n-1)%k;
    int num=0;
    for(int i=0;i<k;i++)
    {
    	if(i<rem)
    	{
    		printf("%d ",move+1);
    		for(int j=0;j<move+1;j++)
    		{
    			printf("%d ",vs[num]+1);
    			num++;
    		}
    		printf("\n");
    	}
    	else
    	{
    		printf("%d ",move);
    		for(int j=0;j<move;j++)
    		{
    			printf("%d ",vs[num]+1);
    			num++;
    		}
    		printf("\n");
    	}
    }
    return 0;
}