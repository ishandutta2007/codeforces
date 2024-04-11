#include <cstdio>
long long n,i;
using namespace std;
int main()
{
    scanf("%I64d",&n);
    if (n&1)
    {
        if (n==1)
        {
            printf("-1\n");
            return 0;
        }
        printf("%I64d %I64d\n",n*n/2,n*n/2+1);
        return 0;
    }
    i=1;
    while (n&1^1)
    {
        n>>=1;
        i<<=1;
    }
    if (n==1)
    {
        if (i>2)
        {
            printf("%I64d %I64d\n",3*i/4,5*i/4);
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    printf("%I64d %I64d\n",n*n/2*i,(n*n/2+1)*i);
    return 0;
}