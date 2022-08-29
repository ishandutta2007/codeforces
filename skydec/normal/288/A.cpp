#include<stdio.h>
using namespace std;
int n,k;
int min(int a,int b){if(a<b)return a;return b;}
int main()
{
    scanf("%d%d",&n,&k);
    if(k>n)
    {
           printf("-1\n");
           return 0;
           }
    if(k==1&&n>1)
    {
                 printf("-1\n");
                 return 0;
                 }
    if(k==1&&n==1)
    {
                  printf("a");
                  return 0;
                  }
    for(int i=1;i<=min(n-(k-2),n);i++)putchar('a'+(i%2==0));
    for(int i=3;i<=k;i++)putchar('a'+i-1);
    return 0;
}