#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long n;
    cin>>n;
    int br=0;
    if(n==4 || n==7 || n==44 || n==74 || n==47 || n==77 || n==444 || n==447 || n==474 || n==744 || n==477 || n==747 || n==774)printf("YES\n");
    else if(n%4==0 || n%7==0 || n%44==0 || n%74==0 || n%47==0 || n%77==0 || n%444==0 || n%447==0 || n%474==0 || n%744==0 || n%477==0 || n%747==0 || n%774==0)printf("YES\n");
    else printf("NO\n");
    return 0;
    }