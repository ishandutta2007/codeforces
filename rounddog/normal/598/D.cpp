#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 1020
#define maxt 1000200
#define inf 1e10

using namespace std;  
int st1[maxt],st2[maxt],ans[maxn][maxn],n,m,top,query,p[maxn][maxn],sum;
bool visit[maxn][maxn],use[maxn][maxn];
char ch;
  
void dfs(int x,int y)
{
	if (use[x][y]){ 
	    visit[x][y]=false;
	    top++;
	    st1[top]=x;
        st2[top]=y;
	    if (visit[x-1][y]) dfs(x-1,y);
    	if (visit[x+1][y]) dfs(x+1,y);
    	if (visit[x][y-1]) dfs(x,y-1);
    	if (visit[x][y+1]) dfs(x,y+1);
    }
} 
  
int main()  
{  
    scanf("%d%d%d",&n,&m,&query);
    memset(use,false,sizeof(use));
    memset(visit,false,sizeof(visit));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
        	do{
			    scanf("%c",&ch);
			}while (ch!='.'&&ch!='*');
        	use[i][j]=(ch=='.');
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
        	p[i][j]=4-use[i-1][j]-use[i+1][j]-use[i][j-1]-use[i][j+1];
        	visit[i][j]=true;
        }
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (visit[i][j]){
            	top=0;sum=0;
            	dfs(i,j);
            	for (int k=1;k<=top;k++) 
            	    sum+=p[st1[k]][st2[k]];
            	while (top){
            		ans[st1[top]][st2[top]]=sum;
            		top--;
            	}
            }
    while (query--)
    {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	printf("%d\n",ans[u][v]);
    }
    return 0;
}