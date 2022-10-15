#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    if(n%4==1) printf("8");
    if(n%4==2) printf("4");
    if(n%4==3) printf("2");
    if(n==0) printf("1"); else if(n%4==0) printf("6");
    return 0;
}