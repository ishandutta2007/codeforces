#include<cstdio>
#include<cstring>
int x[24],y[24],f[1<<24],a[1<<24],p;
#define J(x) __builtin_ctz(x)
inline void C(int &a,int b,int &c,int d){if(a<0||a>b)a=b,c=d;}
inline int S(int x){return x*x;}
int main()
{
    int x0,y0,n,t,i,j,k;
    scanf("%d%d%d",&x0,&y0,&n);
    for(i=0;i<n;scanf("%d%d",x+i,y+i),x[i]-=x0,y[i++]-=y0);
    memset(f,-1,sizeof(f));
    f[p=(1<<n)-1]=0;
    for(k=p;k;k--)
        if(f[k]!=-1)
        {
            i=J(k);
            C(f[k&k-1],(S(x[i])+S(y[i]))*2+f[k],a[k&k-1],k);
            for(t=k&k-1;t;t&=t-1)
            {
                j=J(t);
                C(f[k^(1<<i)^(1<<j)],f[k]+S(x[i])+S(y[i])+S(x[i]-x[j])+S(y[i]-y[j])+S(x[j])+S(y[j]),a[k^(1<<i)^(1<<j)],k);
            }
        }
    printf("%d\n",f[0]);
    for(k=0;k!=p;k=a[k])
    {
        t=a[k]-k,i=J(t),j;
        if(t==(1<<i))
            printf("0 %d ",i+1);
        else
        {
            j=J(t-(1<<i));
            printf("0 %d %d ",i+1,j+1);
        }
    }
    puts("0");
    return 0;
}