#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;double S=1;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=k;i++)S*=(m-i+.0)/(n+i+1);
    printf("%.9lf\n",1-min(S,1.0));
    return 0;
}