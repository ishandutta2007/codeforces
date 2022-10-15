#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000005
using namespace std;
int n,h;
int main()
{
    scanf("%d %d",&n,&h);
    for(int i=1;i<n;i++)
    {
        printf("%lf\n",sqrt((float)h*h*i/n));
    }
    return 0;
}