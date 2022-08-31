#include<stdio.h>
using namespace std;
long n,m,min,max;int have[2]={0};
int main()
{
    scanf("%ld%ld%ld%ld",&n,&m,&min,&max);
    n-=m;
    for(long i=1;i<=m;i++)
    {
             long v;scanf("%ld",&v);
             if(v>max||v<min)
             {
                             printf("Incorrect\n");
                             return 0;
                             }
             if(v==min)have[0]=1;
             if(v==max)have[1]=1;
             }
    long need;
    if(min==max)
    {
                if(!have[0])need=1;else need=0;
                }
    else
    {
        need=2-have[0]-have[1];
        }
    if(n>=need)printf("Correct\n");else printf("Incorrect\n");
    return 0;
}