#include<stdio.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if((n*(n-1)/2)<=k){printf("no solution");}
    else for(int i=1;i<=n;i++)printf("0 %d\n",i);
    return 0;
}