#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int s=0;
    scanf("%d",&n);
    if(n<=10)
        {
        printf("0\n");
        return 0;
        }
    s=n-10;
    if(s>=1 && s<10)printf("4\n");
    if(s==10)printf("15\n");
    if(s==11)printf("4\n");
    if(s>11)printf("0\n");
    return 0;
    }