#include<stdio.h>
#define MAXN 10100000
using namespace std;
bool pr[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=2;n;i++)
    if(!pr[i])
    {
              printf("%d ",i);
              n--;
              for(int j=i*2;j<=10000000;j+=i)pr[j]=1;
              }
    return 0;
}