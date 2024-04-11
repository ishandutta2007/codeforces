#include<stdio.h>
#include<algorithm>
using namespace std;
long n;long h[1000];
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)scanf("%ld",&h[i]);
    sort(h+1,h+1+n);
    for(long i=1;i<=n-1;i++)printf("%ld ",h[i]);
    printf("%ld",h[n]);
    return 0;
}