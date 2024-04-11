#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int p=1,k=0;
    while(k<n)
    {
        k++;
        if(p==1)
        {
            if(a[k]<a[k-1]) p=3;
            if(a[k]==a[k-1]) p=2;
        }
        else if(p==2)
        {
            if(a[k]<a[k-1]) p=3;
            if(a[k]>a[k-1])
            {
                printf("NO\n");
                return 0;
            }
        }
        else if(p==3)
        {
            if(a[k]>=a[k-1])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}