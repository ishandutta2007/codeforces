#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef __int64 ll;
int a[2000+10],n,m;

bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int n,cnt=0;cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            int tmp=1;
            while(tmp*i<=n)
            {
                tmp*=i;
                a[++cnt]=tmp;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d",a[i]);
        if(i==cnt) printf("\n");
        else printf(" ");
    }
    return 0;
}