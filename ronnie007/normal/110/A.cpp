#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long n;
    cin>>n;
    int br=0;
    while(n>0)
        {
        if(n%10==4 || n%10==7)br++;
        n=n/10;
        }
    if(br==0)
        {
        printf("NO\n");
        return 0;
        }
    while(br>0)
        {
        if(br%10!=4 && br%10!=7){printf("NO\n");return 0;}
        br=br/10;
        }
    printf("YES\n");
    return 0;
    }