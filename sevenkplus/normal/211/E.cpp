#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 5010
int n,he[N],ne[N*2],ad[N*2],s[N],d[N],fa[N];
void addE(int x,int y)
{
    static int t=0;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y;
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x;
}
void ff(int x,int y)
{
    s[x]=1,fa[x]=y;
    for(int p=he[x];p;p=ne[p])
        if(ad[p]!=y)ff(ad[p],x),s[x]+=s[ad[p]];
}
bool f[N],S[N];
void upd(int x)
{
    for(int i=n;i>=0;i--)
        if(f[i])f[i+x]=1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),
        --x,--y,addE(x,y),d[x]++,d[y]++;
    ff(0,-1);
    for(int i=0;i<n;i++)
        if(d[i]>1)
        {
            memset(f,0,sizeof f);
            f[0]=1;
            for(int p=he[i];p;p=ne[p])
                if(ad[p]!=fa[i])upd(s[ad[p]]);
            if(i)upd(n-s[i]);
            for(int j=0;j<=n;j++)S[j]|=f[j];
        }
    int p=0;
    for(int i=1;i<n-1;i++)if(S[i])p++;
    printf("%d\n",p);
    for(int i=1;i<n-1;i++)
        if(S[i])printf("%d %d\n",i,n-1-i);
    return 0;
}