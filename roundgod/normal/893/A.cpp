#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(a[0]==3)
    {
        printf("NO\n");
        return 0;
    }
    int spec=3;
    for(int i=1;i<n;i++)
    {
        spec=6-a[i-1]-spec;
        if(a[i]==spec)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}