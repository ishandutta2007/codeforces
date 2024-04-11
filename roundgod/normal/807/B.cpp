#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 475
#define INF 10000000
using namespace std;
int save[MAXN],p,x,y;
int main()
{
    scanf("%d %d %d",&p,&x,&y);
    int limit=(x-y)/50;
    int i=0,t;
    for(int j=0;j<475;j++)
    {
        save[j]=i;
        if(i+26==p) t=j;
        i=(i*96+42)%475;
    }
    i=0;
    int ans=INF;
    for(int i=1;i<26;i++)
    {
        int ind=t-i;
        if(ind<0) ind+=475;
        int m=x/50;
        if(limit==0&&(m-save[ind])%2==1) continue;
        if(save[ind]<=m)
        {
            if(m-save[ind]>limit)
            {
                ans=min(ans,(int)(476+save[ind]-m)/2);
            }
            else
            {
                ans=0;
                break;
            }
        }
        else ans=min(ans,(int)((save[ind]-m+1)/2));
    }
    printf("%d\n",ans);
    return 0;
}