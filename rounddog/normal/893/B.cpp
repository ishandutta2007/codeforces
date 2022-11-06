#include<bits/stdc++.h>
#define maxn 200005

using namespace std;

int n,a[20],k,t;

int main()
{
    t=1;
    for (int i=0;i<10;i++)
    {
        a[i]=t*(t*2-1);
        t=t*2;
    }
    scanf("%d",&n);
    for (int i=9;i>=0;i--) if (n%a[i]==0) {printf("%d\n",a[i]);break;}
    return 0;
}