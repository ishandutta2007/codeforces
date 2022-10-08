#include<cstdio>
#include<algorithm>
using namespace std;
inline void e(){puts("No");exit(0);}
inline void f(){puts("Yes");}
int n,w,a[1111];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int S=0;
    for(int i=1;i<=n;i++)S+=a[i];
    if(1>w||w>S)e();
    if(n==1)
    {
        if(S!=w)e();f();
        for(int i=1;i<=w;i++)printf("1 1%c",i==w?'\n':' ');
    }else
    if(w==1)
    {
        int p=-1;
        for(int i=1;i<=n;i++)if(a[i]==1)p=i;
        if(p==-1)e();f();
        printf("%d",p);
        for(int i=1;i<=n;i++)if(i!=p)
            for(int j=1;j<=a[i];j++)printf(" %d %d",i,i);
        printf(" %d\n",p);
    }else
    if(w<=a[1])
    {
        f();
        for(int i=1;i<=w-2;i++)printf("1 1 ");
        printf("2 ");
        for(int i=w-1;i<a[1];i++)printf("1 1 ");
        printf("2 ");
        printf("1 ");
        a[2]--;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=a[i];j++)printf("%d %d ",i,i);
        puts("1");
    }else
    {
        f();
        for(int i=1;i<=a[1]-1;i++)printf("1 1 ");
        w-=a[1];
        for(int i=2;i<=n;i++)
            if(w>a[i])
            {
                w-=a[i];
                for(int j=1;j<=a[i];j++)printf("%d %d ",i,i);
            }else
            if(w==0)
            {
                for(int j=1;j<=a[i];j++)printf("%d %d ",i,i);
            }else
            {
                for(int j=1;j<=w;j++)printf("%d %d ",i,i);
                printf("1 ");
                for(int j=w+1;j<=a[i];j++)printf("%d %d ",i,i);
                w=0;
            }
        puts("1");
    }
    return 0;
}