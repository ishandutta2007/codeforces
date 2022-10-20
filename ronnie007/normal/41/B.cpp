#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int a[2050];
    int n;
    int m;
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    int ans=m;
    int x,y;
    for(i=0;i<n;i++)
        {
        for(j=i+1;j<n;j++)
            {
            x=m/a[i];
            y=m%a[i];
            if(ans<y+x*a[j])ans=y+x*a[j];
            }
        }
    printf("%d\n",ans);
    return 0;
    }