#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
double p[105];
long n;
double he,all;
int main()
{
    scanf("%ld",&n);
    he=0;all=1;
    double ans=0;
    for(long i=1;i<=n;i++)
    {
             scanf("%lf",&p[i]);
             if(p[i]==1.0)
             {
                        printf("1\n");
                        return 0;
                        }
             if(p[i]>ans)ans=p[i];
             }
    sort(p+1,p+1+n);
    for(long i=1;i<=n;i++)
    for(long j=i;j<=n;j++)
    {
             double all=0;double s1;
             for(long k=i;k<=j;k++)
             {
                      s1=1;
                      for(long s=i;s<=j;s++)
                      if(s!=k)
                      {
                              s1*=(1-p[s]);
                              }
                      all+=s1*p[k];
                      }
             if(all>ans)ans=all;
             }
    printf("%.10lf\n",ans);
    return 0;
}