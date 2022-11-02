#include<cstdio>
#include<algorithm>

using namespace std;

int ans[1<<21],flag[1<<21];
int a[110],opt[110],c[110];
int n,m;
char s[10];

inline int cmp(int a,int b)
{
    return a>b;
}

int dfs(int now,int x)
{
    if(flag[now])return ans[now];
    if(x>m)return 0;
    flag[now]=1;
    int nowans=0,Now=now;
    while(x<=m)
    {
        if(opt[x])
        {
            for(int i=0;i<m;i++)
                if(!(now&(1<<i)))
                {
                    if(c[x]==1)nowans+=a[i+1];
                    else nowans-=a[i+1];
                    now|=1<<i;
                    break;
                }
        }
        else
        {
            int nowm;
            if(c[x]==1)nowm=-0x7f7f7f7f;
            else nowm=0x7f7f7f7f;
            for(int i=0;i<m;i++)
                if(!(now&(1<<i)))
                {
                    int noww=dfs(now|(1<<i),x+1);
                    if(c[x]==1)nowm=max(nowm,noww);
                    else nowm=min(nowm,noww);
                }
            nowans+=nowm;
            break;
        }
        x++;
    }
    return ans[Now]=nowans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s%d",s,&c[i]);
        opt[i]=(s[0]=='p');
    }
    printf("%d\n",dfs(0,1));
}