#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if (n==1) return printf("1\n1\n"),0;
    if (n==2) return printf("1\n1\n"),0;
    if (n==3) return printf("2\n1 3\n"),0;
    if (n&1)
    {
        printf("%d\n",n);
        for (int i=n;i>=1;i-=2) printf("%d ",i);
        for (int i=n-1;i>=1;i-=2) printf("%d ",i);puts("");
    } else
    {
        printf("%d\n",n);
        for (int i=n-1;i>=1;i-=2) printf("%d ",i);
        for (int i=n;i>=1;i-=2) printf("%d ",i);puts("");
    }
}