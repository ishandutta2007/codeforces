#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<bitset>
#define MAXN 2005
using namespace std;
bitset<MAXN>a[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
            int x;scanf("%d",&x);
            a[i][j]=(x>0);
            }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    if(a[i][k])a[i]|=a[k];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(!a[i][j])
    {
                printf("NO\n");
                return 0;
                }
    printf("YES\n");
    return 0;
}