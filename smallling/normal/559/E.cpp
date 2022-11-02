#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

map<pair<int,int>,int>f;

struct lhy{
    int x,y;
}a[110];

int n;

int dfs(int x,int r)
{
    if(x>n)return 0;
    if(f[make_pair(x,r)])return f[make_pair(x,r)];
    int nowans=0;
    for(int i=x;i<=n;i++)
    {
        int nowr=a[i].x,nowto=i,nowAns=a[i].x-max(a[i].x-a[i].y,r);
        for(int j=x;j<=n&&a[j].x<=nowr;j++)
            if(i^j)
            {
                nowto=max(nowto,j);
                if(a[j].x+a[j].y>nowr)
                {
                    nowAns+=a[j].x+a[j].y-nowr;
                    nowr=a[j].x+a[j].y;
                }
            }
        nowAns+=dfs(nowto+1,nowr);
        nowans=max(nowans,nowAns);
    }
    int nowr=a[x].x+a[x].y,nowto=x,nowAns=a[x].y;
    for(int i=x+1;i<=n&&a[i].x<=nowr;i++)
    {
        nowto=i;
        if(a[i].x+a[i].y>nowr)
        {
            nowAns+=a[i].x+a[i].y-nowr;
            nowr=a[i].x+a[i].y;
        }
    }
    nowAns+=dfs(nowto+1,nowr);
    nowans=max(nowans,nowAns);
    return f[make_pair(x,r)]=nowans;
}

inline int cmp(const lhy &a,const lhy &b)
{
    return a.x<b.x;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    printf("%d",dfs(1,-1000000001));
}