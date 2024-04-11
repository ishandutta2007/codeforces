#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
    {
    int a[10];
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    sort(a,a+4);
    int i;
    int br=0;
    for(i=1;i<4;i++)
        {
        if(a[i]==a[i-1])br++;
        }
    printf("%d\n",br);
    return 0;
    }