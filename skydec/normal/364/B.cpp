#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAXN (55)
using namespace std;
int data[MAXN];
bool f[510000];
int n,d;
#define MIN(a,b) ((a)<(b)?(a):(b))
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    sort(data+1,data+1+n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
            if(data[i]>sum+d)
            {
                             n=i-1;break;
                             }
            else sum+=data[i];
            }
    f[0]=1;
    for(int i=1;i<=n;i++)
    for(int j=500000;j>=data[i];j--)
    f[j]|=f[j-data[i]];
    int step=0;int now=0;
    for(step=1;;step++)
    {
                       int u=-1;
                       for(int k=now+d;k>=now+1;k--)
                       if(f[k]){u=k;break;}
                       if(u==-1){printf("%d %d\n",now,step-1);return 0;}
                       now=u;
                       }
    return 0;
}