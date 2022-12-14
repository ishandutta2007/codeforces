#include<bits/stdc++.h>
using namespace std;
long long num[5000001];
int main()
{
    num[1]=0;
    num[2]=1;
    for (int i=2;i<=5000000;i++)
    {
        int j=2;
        while(i%j && j*j<=i)j++;
        if (j*j>i)num[i]=1;
        else num[i]=1+num[i/j];
    }
    for (int i=2;i<=5000000;i++)
        num[i]+=num[i-1];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",num[a]-num[b]);
    }
}