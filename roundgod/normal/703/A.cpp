#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100
using namespace std;
int n,x,y,a,b;
int main()
{
    scanf("%d",&n);
    a=b=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y) a++; else if(y>x) b++;
    }
    if(a>b) printf("Mishka");
    if(a<b) printf("Chris");
    if(a==b) printf("Friendship is magic!^^");
    return 0;
}