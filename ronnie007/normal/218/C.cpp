#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int n;
int ans=0;
int par[127];
int find(int p1)
    {
    if(par[p1]==-1)return p1;
    return find(par[p1]);
    }
int unin(int p1,int p2)
    {
    p1=find(p1);
    p2=find(p2);
    if(p1!=p2)
        {
        par[p1]=p2;
        ans--;
        }
    }

int main()
    {
    scanf("%d",&n);
    int i,j;
    int x[127];
    int y[127];
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x[i],&y[i]);
        par[i]=-1;
        }
    ans=n-1;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            if(x[i]==x[j] || y[i]==y[j])unin(i,j);
            }
        }
    printf("%d\n",ans);
    return 0;
    }