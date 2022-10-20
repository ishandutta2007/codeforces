#include<iostream>
#include<stdio.h>
using namespace std;


int used[100007];

int main()
    {
    int n;
    int x,y;
    scanf("%d",&n);
    int i,j;
    int p;
    int ans=0;
    for(i=0;i<=100000;i++)used[i]=-2007;
    for(i=1;i<=n;i++)
        {
        scanf("%d%d",&x,&y);
        ans=0;
        for(j=1;j*j<=x;j++)
            {
            if(x%j==0)
                {
                if(used[j]<=(i-y-1)){ans++;}
                used[j]=i;
                }
            p=x/j;
            if(p==j)continue;
            if(x%p==0)
                {
                if(used[p]<=(i-y-1)){ans++;}
                used[p]=i;
                }
            }
        printf("%d\n",ans);
        }
    return 0;
    }