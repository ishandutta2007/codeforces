#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,o,a[110];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&o),a[o]=1;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&o),a[o]=1;
    for(int i=1;i<=n;i++)
        if(!a[i])return puts("Oh, my keyboard!"),0;
    puts("I become the guy.");
}