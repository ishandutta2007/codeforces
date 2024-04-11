#include<cstdio>

using namespace std;

long long n,m,o,sum;

int main()
{
    scanf("%I64d%I64d",&n,&m);
    o=n%m;
    sum=n/m;
    printf("%I64d ",sum*(sum-1)/2*(m-o)+sum*(sum+1)/2*o);
    printf("%I64d",(n-m+1)*(n-m)/2);
}