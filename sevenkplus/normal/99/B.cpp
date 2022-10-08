#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int *l0=min_element(a,a+n),*l1=max_element(a,a+n);
    if(*l0==*l1)puts("Exemplary pages.");else
    {
        int m=(*l1-*l0)/2;
        *l1-=m,*l0+=m;
        if(*min_element(a,a+n)==*max_element(a,a+n))printf("%d ml. from cup #%d to cup #%d.\n",m,l0-a+1,l1-a+1);
        else puts("Unrecoverable configuration.");
    }
    return 0;
}