#include<cstdio>
#include<algorithm>
using namespace std;
int n;double p[110],S;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)scanf("%lf",p+i);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(i*2<=n&&n<=j*2)S=max(S,(n*0.5-j)/(i-j)*p[i]+(n*0.5-i)/(j-i)*p[j]);
    printf("%.9lf\n",S);
    return 0;
}