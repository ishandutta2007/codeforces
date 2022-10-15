#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000
using namespace std;
int a[MAXN],b[MAXN],n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]!=a[i])
        {
            printf("rated\n");
            return 0;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            printf("unrated\n");
            return 0;
        }
    }
    printf("maybe\n");
    return 0;
}