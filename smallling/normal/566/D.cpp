#include<cstdio>

using namespace std;

int n,m,x,y,opt,now,f[200020],fa[200020];

int getfa(int v)
{
    if(fa[v]==v)return v;
    return fa[v]=getfa(fa[v]);
}

int getf(int v)
{
    if(f[v]==v)return v;
    return f[v]=getf(f[v]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&opt,&x,&y);
        if(opt==3)
        {
            if(getfa(x)==getfa(y))puts("YES");
            else puts("NO");
        }
        else
        if(opt==1)fa[getfa(x)]=getfa(y);
        else
        {
            while(x<=y)
            {
                now=getf(x);
                if(now<=y)f[now]=y;
                if(now+1<=y)fa[getfa(now+1)]=getfa(x);
                x=now+1;
            }
        }
    }
}