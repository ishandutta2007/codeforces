#include<iostream>
#include<stdio.h>
using namespace std;

int n,d;
int a[100007];
long long br=0;

int main()
    {
    scanf("%d %d",&n,&d);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    int l;
    int r;
    int m;
    long long k;
    for(i=1;i<=n-2;i++)
        {
        l=i+2;
        r=n;
        while(l!=r)
            {
            m=(l+r)/2;
            if(a[m]-a[i]<=d)
                {
                l=m+1;
                }
            else
                {
                r=m;
                }
            //printf("%d %d\n",l,r);
            }
        if(a[l]-a[i]>d)l--;
        k=(l-i);
        br+=k*(k-1)/2;
        }
    cout<<br<<"\n";
    return 0;
    }