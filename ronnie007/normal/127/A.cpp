#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;


double dist(int x1,int y1,int x2,int y2)
    {
    return sqrt(abs(x1-x2)*double(abs(x1-x2)) + abs(y1-y2)*double(abs(y1-y2)));
    }


int main()
    {
    int n;
    int i;
    int x[3000];
    int y[3000];
    int k=0;
    double ans=0.000000;
    scanf("%d%d",&n,&k);
    scanf("%d%d",&x[0],&y[0]);
    for(i=1;i<n;i++)
        {
        scanf("%d%d",&x[i],&y[i]);
        ans+=dist(x[i],y[i],x[i-1],y[i-1]);
        }
    printf("%.9lf\n",ans*k/50);
    return 0;
    }