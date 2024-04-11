#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int n,x,y;
int main()
{
    scanf("%d",&n);
    scanf("%d:%d",&x,&y);
    if(y>=60) y=10+y%10;
    if(n==24)
    {
        if(x>23) x=10+x%10;
    }
    if(n==12)
    {
        if(x==0) x=1;
        else if(x>12)
        {
            if(x%10==0) x=10;
            else x=x%10;
        }
    }
    if(x<10) printf("0%d:",x); else printf("%d:",x);
    if(y<10) printf("0%d",y); else printf("%d",y);
    return 0;
}