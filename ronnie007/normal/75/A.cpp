#include<iostream>
#include<stdio.h>
using namespace std;

int q(int x);

int main()
    {
    int a,b,c;
    int a1,b1,c1;
    scanf("%d%d",&a,&b);
    c=a+b;
    a1=q(a);
    b1=q(b);
    c1=q(c);
    if(a1+b1==c1)printf("YES\n");
    else printf("NO\n");
    return 0;
    }


int q(int x)
    {
    int ans=0;
    int t=1;
    while(x>0)
        {
        ans+=(x%10)*t;
        if(x%10!=0)t=t*10;
        x=x/10;
        }
    //printf("%d\n",ans);
    return ans;
    }