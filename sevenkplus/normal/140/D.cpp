#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[111],S=0,S0=0,T=10;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        T+=a[i];
        if(T>720)break;
        else S0++,S+=max(0,T-360);
    }
    printf("%d %d\n",S0,S);
    return 0;
}