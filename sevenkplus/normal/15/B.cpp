#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    long long n,m,a,b,c,d;
    for(scanf("%d",&t);t--;)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&a,&b,&c,&d);
        a=abs(a-c),b=abs(b-d);
        printf("%I64d\n",n*m-2*(n-a)*(m-b)+max(n-2*a,0LL)*max(m-2*b,0LL));
    }
    return 0;
}