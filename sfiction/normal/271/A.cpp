/*
ID: Sfiction
OJ: CF
PROB: 271A
*/
#include <cstdio>
char f[10000];
int main()
{
    int N,i,j,k,l;
    for (i=1;i<10;++i)
        for (j=0;j<10;++j)
            if (j!=i)
                for (k=0;k<10;++k)
                    if (k!=i&&k!=j)
                        for (l=0;l<10;++l)
                            if (l!=i&&l!=j&&l!=k) f[i*1000+j*100+k*10+l]=1;
    scanf("%d",&N);
    for (++N;!f[N];++N);
    printf("%d",N);
    return 0;
}