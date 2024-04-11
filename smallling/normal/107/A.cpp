#include<cstdio>
#include<algorithm>

using namespace std;

struct lhy{
    int x,y,l;
}ans[1010];

int n,m,h,x,y,l,Ans,d,ru[1010],chu[1010];
pair<int,int>g[1010];

int main()
{
    scanf("%d%d",&n,&m);
    if(!m)return puts("0"),0;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&x,&y,&d),g[x]=make_pair(y,d),ru[y]++,chu[x]++;
    for(int i=1;i<=n;i++)
        if(!ru[i]&&chu[i])
        {
            int now=i;
            int nowans=0x3f3f3f3f;
            ans[++Ans].x=now;
            while(g[now].first)nowans=min(nowans,g[now].second),now=g[now].first;
            ans[Ans].y=now;
            ans[Ans].l=nowans;
        }
    printf("%d\n",Ans);
    for(int i=1;i<=Ans;i++)
        printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].l);
}