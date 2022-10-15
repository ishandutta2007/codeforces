#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 10000000
using namespace std;
int a,b,x,y,z,n;
double mini;
int main()
{
    scanf("%d%d",&a,&b);
    scanf("%d",&n);
    mini=INF;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        mini=min(mini,sqrt((x-a)*(x-a)+(y-b)*(y-b))/z);
    }
    printf("%lf\n",mini);
    return 0;
}