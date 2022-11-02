#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,x,y,s1,t1,l1,s2,t2,l2,h,l,L1,L2,ans;
int flag[3030],q[3030],dis[3030][3030];
vector<int>a[3030];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(dis,0x3f,sizeof(dis));
    for(int x=1;x<=n;x++)
    {
        h=l=0;
        q[++l]=x;
        for(int i=1;i<=n;i++)flag[i]=0;
        flag[x]=1;
        dis[x][x]=0;
        while(h<l)
        {
            int v=q[++h];
            for(int i=0;i<a[v].size();i++)
                if(!flag[a[v][i]])dis[x][a[v][i]]=dis[x][v]+1,flag[a[v][i]]=1,q[++l]=a[v][i];
        }
    }
    scanf("%d%d%d",&s1,&t1,&l1);
    scanf("%d%d%d",&s2,&t2,&l2);
    if(dis[s1][t1]>l1||dis[s2][t2]>l2)return puts("-1"),0;
    ans=dis[s1][t1]+dis[s2][t2];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            L1=min(dis[s1][i]+dis[j][t1],dis[s1][j]+dis[i][t1]);
            L2=min(dis[s2][i]+dis[j][t2],dis[s2][j]+dis[i][t2]);
            if(L1+dis[i][j]>l1||L2+dis[i][j]>l2)continue;
            ans=min(ans,dis[i][j]+L1+L2);
        }
    printf("%d",m-ans);
}