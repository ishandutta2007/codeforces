#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;



int main()
    {
    int n;
    int i;
    scanf("%d",&n);
    int p=n/4;
    for(i=0;i<p;i++)
        {
        printf("abcd");
        }
    n=n%4;
    if(n>=1)printf("a");
    if(n>=2)printf("b");
    if(n>=3)printf("c");
    if(n>=4)printf("d");
    printf("\n");
    return 0;
    }