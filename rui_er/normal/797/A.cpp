#include <stdio.h>
#include <math.h>
using namespace std;

int n, k, g = 1, p[101];

namespace add
{
}

int main(void)
{
    scanf("%d %d", &n, &k);
    for(int i=2,q=sqrt(n);i<=q;i++) while(not(n % i)) p[++p[0]] = i, n /= i;
    if(n != 1) p[++p[0]] = n;
    if(p[0] < k)
	{
		printf("-1\n");
		return 0;
	}
    for(int i=1;i<k;i++) printf("%d ", p[i]);
    for(int i=k;i<=p[0];i++) g *= p[i];
    printf("%d\n", g);
    return 0;
}