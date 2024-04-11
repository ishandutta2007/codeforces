#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 100
using namespace std;
int n,k,f;
int a[MAXN],b[MAXN];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    if(k>=2)
    {
        printf("YES\n");
        return 0;
    }
    for(int i=0;i<n;i++)
        if(a[i]==0) a[i]=b[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i-1])
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}