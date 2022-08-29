#include<stdio.h>
#include<algorithm>
using namespace std;
struct group
{
       long use,num,cost;
}gr[1005];
struct table
{
       long num,frees;
}ta[1005];
bool cmpgroup(group a,group b){return a.cost>b.cost;}
bool cmptable(table a,table b){return a.frees<b.frees;}
long n,m;bool have[1005]={false};long bedone[1005]={0};
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             long a,b;scanf("%ld%ld",&a,&b);
             gr[i].num=i;
             gr[i].cost=b;
             gr[i].use=a;
             }
    scanf("%ld",&m);
    for(long i=1;i<=m;i++)
    {
             long a;scanf("%ld",&a);
             ta[i].num=i;
             ta[i].frees=a;
             }
    sort(gr+1,gr+1+n,cmpgroup);
    sort(ta+1,ta+1+m,cmptable);long sum=0;
    for(long i=1;i<=n;i++)
    {
             long y=0;
             for(long j=1;j<=m;j++)
             if(!have[ta[j].num]&&ta[j].frees>=gr[i].use)
             {
                                                 y=ta[j].num;
                                                 break;
                                                 }
             if(y)
             {
              have[y]=true;bedone[gr[i].num]=y;
              sum+=gr[i].cost;
              }
             }
    long tot=0;
    for(long i=1;i<=n;i++)if(bedone[i])tot++;
    printf("%ld %ld\n",tot,sum);
    for(long i=1;i<=n;i++)
    if(bedone[i])
    {
                 printf("%ld %ld\n",i,bedone[i]);
                 }
    //for(;;);
    return 0;
}