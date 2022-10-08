#include<cstdio>
#include<cmath>
#define N 100010
int n,m,K,a[N],g[N],r[N],c[N],k,x,y,s;
void F(int R,int L)
{
    for(int i=R;i>=L;i--)
    {
        if(i+a[i]>n)
            r[i]=0,c[i]=1;
        else
            if(!r[i+a[i]]||g[i+a[i]]>g[i])
                r[i]=i+a[i],c[i]=1;
            else
                r[i]=r[i+a[i]],c[i]=c[i+a[i]]+1;
    }
}
int main()
{
    scanf("%d%d",&n,&m),K=int(sqrt(n));
    for(int i=1;i<=n;scanf("%d",&a[i]),g[i]=i/K,i++);
    F(n,1);
    for(;m--;)
    {
        scanf("%d",&k);
        if(k)
        {
            scanf("%d",&x);
            for(s=0;x;y=x,s+=c[x],x=r[x]);
            printf("%d %d\n",y,s);
        }
        else
        {
            scanf("%d%d",&x,&y);
            a[x]=y,F(x,x-x%K);
        }
    }
    return 0;
}