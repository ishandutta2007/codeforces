#include<stdio.h>
using namespace std;
long n,a,b;
bool love1[105]={false};
bool love2[105]={false};
bool give[105]={false};
int main()
{
    scanf("%ld%ld%ld",&n,&a,&b);
    for(long i=1;i<=a;i++)
    {
             long v;scanf("%ld",&v);love1[v]=true;
             give[v]=true;
             }
    for(long i=1;i<=b;i++)
    {
             long v;scanf("%ld",&v);love2[v]=true;
             }
    for(long i=1;i<=n;i++)if(give[i])printf("1 ");else printf("2 ");
    return 0;
}