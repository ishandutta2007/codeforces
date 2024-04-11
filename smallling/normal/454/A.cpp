#include<cstdio>

using namespace std;

int n,now;

int main()
{
    scanf("%d",&n);
    now=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(n-now)/2;j++)
            putchar('*');
        for(int j=1;j<=now;j++)
            putchar('D');
        for(int j=1;j<=(n-now)/2;j++)
            putchar('*');
        putchar('\n');
        if(i<=n/2)now+=2;
        else now-=2;
    }
}