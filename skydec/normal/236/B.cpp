#include<stdio.h>
#define jsb 1073741824
using namespace std;
int a,b,c;
int ans[1000005];
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=a*b*c;i++)
    for(int j=i;j<=a*b*c;j+=i)ans[j]++;
    int reu=0;
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++)
    for(int k=1;k<=c;k++)
    reu=(reu+ans[i*j*k])%jsb;
    printf("%d\n",reu);
    return 0;
}