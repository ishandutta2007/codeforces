/*
ID: Sfiction
OJ: CF
PROB: 268B
*/
/*
iN-i+1i*(N-i+1)i-1

NAi(1iNiZ)
ai=i*(N-i+1)-(i-1)=N*i-i*i+1

S=N*N*(N+1)/2-N*(N+1)*(2N+1)/6+N
 =N*(N+1)*(N-1)/6+N
 =N*(N^2+5)/6
long long
*/
#include <cstdio>
int main()
{
    long long N;
    scanf("%I64d",&N);
    printf("%I64d",N*(N*N+5)/6);
    return 0;
}