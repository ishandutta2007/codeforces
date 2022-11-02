#include<map>
#include<cstdio>
#include<cstring>

using namespace std;

map<int,int>bo;

int n,a,b;
int ans[100010],p[100010],f[100010][2];

int dfs(int x,int color)
{
    if(x==-1)return 1;
    if(ans[x]!=-1)return 1;
    if(f[x][color]!=-1&&ans[f[x][color]]==-1)
    {
        ans[x]=ans[f[x][color]]=color;
        if((dfs(f[x][!color],color)&dfs(f[f[x][color]][!color],color))==0)return ans[x]=ans[f[x][color]]=-1,0;
    }
    else return 0;
    return ans[x]=ans[f[x][color]]=-1,1;
}

void paint(int x,int color)
{
    if(x==-1||ans[x]!=-1)return;
    ans[x]=color;
    paint(f[x][0],color);
    paint(f[x][1],color);
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        bo[p[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(bo.find(a-p[i])!=bo.end())f[i][0]=bo[a-p[i]];
        else f[i][0]=-1;
        if(bo.find(b-p[i])!=bo.end())f[i][1]=bo[b-p[i]];
        else f[i][1]=-1;
        if(f[i][0]==-1&&f[i][1]==-1)return puts("NO"),0;
    }
    memset(ans,-1,sizeof(ans)); 
    for(int i=1;i<=n;i++)
    {
        if(ans[i]!=-1)continue;
        if(f[i][0]!=-1&&dfs(i,0))paint(i,0),ans[i]=0;
        else if(f[i][1]!=-1&&dfs(i,1))paint(i,1),ans[i]=1;
        else return puts("NO"),0;
    }
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}