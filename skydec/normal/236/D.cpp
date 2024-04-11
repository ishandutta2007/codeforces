#include<stdio.h>
using namespace std;
int n;
double ans=0;
double len=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            double p;scanf("%lf",&p);
            ans+=p*(2*len+1);
            len=(len+1)*p;
            }
    printf("%.10lf\n",ans);
    return 0;
}