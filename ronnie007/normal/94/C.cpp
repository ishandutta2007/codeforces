#include<iostream>
#include<stdio.h>
using namespace std;

int n,m,a,b;

int f();

int main()
    {
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans=0;
    if(m==1)
        {
        printf("1\n");
        return 0;
        }
    if ( ((a-1)%m)+1==((b-1)%m)+2 )
        {
        printf("2\n");
        return 0;
        }
    if ( f()==1 || ( ( a%m == 1 || a == 1 ) && ( b%m == 0 || b == n ) ) )ans=1;
    else if(f()==2)ans=2;
    else if(b%m == 0 || b==n)ans=2;
    else if(a%m==1 || a==1)ans=2;
    else ans=3;
    printf("%d\n",ans);
    return 0;
    }


int f()
    {
    if(m==1)return b-a+1;
    int p,t;
    p=a;
    t=b;
    ///while(p%m!=1)p--;
    ///while(t%m!=1)t--;
    p=p-(p-1)%m;
    t=t-(t-1)%m;
    int ans=((t-p)/m+1);
    return ans;
    }