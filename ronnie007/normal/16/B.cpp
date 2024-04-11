#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct tuhla
    {
    int x,y;
    };
struct tuhla a[27];

bool f(struct tuhla p1,struct tuhla p2)
    {
    if(p1.y>p2.y)return true;
    return false;
    }

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&a[i].x,&a[i].y);
        }
    sort(a,a+m,f);
    long long sm=0;
    for(i=0;i<m;i++)
        {
        if(n>=a[i].x)
            {
            n=n-a[i].x;
            sm=sm+a[i].x*a[i].y;
            }
        else
            {
            sm=sm+n*a[i].y;
            break;
            }
        }
    printf("%I64d\n",sm);
    return 0;
    }