#include<iostream>
#include<stdio.h>
using namespace std;

int n,k;
int br[150];
int p[150];

int main()
    {
    scanf("%d%d",&n,&k);
    int i,j;
    int x;
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        br[x]++;
        }
    int ans=0;
    while(br[k]!=n)
        {
        for(i=1;i<=k;i++)p[i]=0;
        for(i=1;i<k;i++)
            {
            if(br[i]!=0)
                {
                br[i]--;
                p[i+1]=1;
                }
            }
        for(i=2;i<=k;i++)
            {
            if(p[i]==1)
                {
                br[i]++;
                }
            }
        ans++;
        }
    printf("%d\n",ans);
    return 0;
    }