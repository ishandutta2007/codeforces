/*
ID: Sfiction
OJ: CF
PROB: 297A
*/
#include <cstdio>
const int MAXN=1000;
char a[MAXN+1];
char b[MAXN+1];
int main()
{
    int i;
    int suma,sumb;
    scanf("%s",a);
    scanf("%s",b);
    for (suma=i=0;a[i];++i) suma+=a[i]=='1';
    for (sumb=i=0;b[i];++i) sumb+=b[i]=='1';
    suma+=suma&1;
    if (suma>=sumb) printf("YES");
    else printf("NO");
    return 0;
}