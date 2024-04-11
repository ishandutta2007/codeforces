#include<iostream>
#include<stdio.h>
using namespace std;
int main()
    {
    int n;
    int a[150];
    int b[150];
    int c[150];
    int i;
    int suma=0;
    int sumb=0;
    int sumc=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        suma+=a[i];
        sumb+=b[i];
        sumc+=c[i];
        }
    if(suma!=0 || sumb!=0 || sumc!=0)
        {
        printf("NO\n");
        return 0;
        }
    else printf("YES\n");
    return 0;
    }