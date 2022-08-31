#include<stdio.h>
#include<cmath>
using namespace std;
int n,m;
int main()
{
    double ans=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)ans+=(pow(((double)i/m),n)-pow(((double)(i-1)/m),n))*i;
    printf("%.10lf\n",ans);
    return 0;
}