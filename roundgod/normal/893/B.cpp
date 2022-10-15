#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    for(int i=1;i<10;i++)
        a[i]=((1<<i)-1)*(1<<(i-1));
    scanf("%d",&n);
    for(int i=9;i>=0;i--)
        if(n%a[i]==0)
        {
            printf("%d\n",a[i]);
            return 0;
        }
    return 0;
}