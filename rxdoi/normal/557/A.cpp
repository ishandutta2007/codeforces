#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int n,a1,b1,a2,b2,a3,b3,x1,x2,x3;

int main()
{
    n=IN();
    a1=IN(),b1=IN();
    a2=IN(),b2=IN();
    a3=IN(),b3=IN();
    printf("%d ",x1=min(n-a2-a3,b1));n-=x1;
    printf("%d ",x2=min(n-a3,b2));n-=x2;
    printf("%d\n",x3=n);
}