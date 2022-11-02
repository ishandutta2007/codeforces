#include<cstdio>

using namespace std;

int n,last,now,b[1000100],m,o;

int main()
{
    scanf("%d",&n);
    last=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o);
        now=o+last-1;
        for(int j=last;j<=now;j++)
            b[j]=i;
        last=now+1;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&o);
        printf("%d\n",b[o]);
    }
}