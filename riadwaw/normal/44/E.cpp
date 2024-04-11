#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
int main(){
//    freopen("input.txt","r",stdin);
    int n,b,a,k;
    char c[205];
    scanf("%d%d%d",&k,&a,&b);
    gets(c);
    gets(c);
    n=strlen(c);
    if(b*k<n || a*k>n)
    {
        printf("No solution");
        return 0;
    }
    int l=n/k;
    int z=n%k;
    for(int i=0;i<z;i++)
    {
        for(int j=i*(l+1);j<(i+1)*(l+1);j++)
            printf("%c",c[j]);
        printf("\n");
    }
    for(int i=0;i<k-z;i++)
    {
        for(int j=z*(l+1)+i*l;j<z*(l+1)+(i+1)*l;j++)
            printf("%c",c[j]);
        printf("\n");
    }
    return 0;
}