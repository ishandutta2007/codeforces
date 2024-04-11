#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
long n,k;
long data[MAXN];
long sum=0;
bool cmp(long a,long b){return a<b;}
int main()
{
    scanf("%ld%ld",&n,&k);
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&data[i]);
             if(data[i]<0&&k)
             {
                             k--;
                             data[i]=-data[i];
                             }
             sum+=data[i];
                             }
    if(!k)printf("%ld\n",sum);
    else
    {
        if(k%2==0)
        {
                  printf("%ld\n",sum);
                  }
        else
        {
                  sort(data+1,data+1+n,cmp);
                  sum-=2*data[1];
                  printf("%ld\n",sum);
                  }
                  }
    return 0;
}