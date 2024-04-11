#include<stdio.h>
#include<algorithm>
#include<cstring>
#define pii pair<int,int>
#define MAXN 1005
using namespace std;
char str[MAXN][MAXN];
int r,c;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int dis[MAXN][MAXN];
pii q[MAXN*MAXN];
pii st,person;
#define fi first
#define se second
int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)scanf("%s",str[i]+1);
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    {
            if(str[i][j]=='E')st=pii(i,j);
            if(str[i][j]=='S')person=pii(i,j);
            }
    int top=1;q[top]=st;dis[st.fi][st.se]=1;
    for(int i=1;i<=top;i++)
    {
            int x=q[i].fi;
            int y=q[i].se;
            for(int k=1;k<=4;k++)
            {
                    int x1,y1;
                    x1=x+dx[k];
                    y1=y+dy[k];
                    if(x1<=0||x1>r)continue;
                    if(y1<=0||y1>c)continue;
                    if(dis[x1][y1])continue;
                    if(str[x1][y1]=='T')continue;
                    dis[x1][y1]=dis[x][y]+1;
                    q[++top]=pii(x1,y1);
                    }
                    }
    int ans=0;
    for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
    if(dis[i][j])
    if(dis[i][j]<=dis[person.fi][person.se])
    if(str[i][j]>='0'&&str[i][j]<='9')ans+=str[i][j]-48;
    printf("%d\n",ans);
    return 0;
}