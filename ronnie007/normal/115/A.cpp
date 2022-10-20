#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int ans=0;
int p[2007];

void dfs(int vertex,int br);

int main()
    {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&p[i]);
        }
    for(i=1;i<=n;i++)
        {
        if(p[i]==-1)dfs(i,1);
        }
    printf("%d\n",ans);
    return 0;
    }


void dfs(int vertex,int br)
    {
    int i;
    if(ans<br)ans=br;
    for(i=1;i<=n;i++)
        {
        if(p[i]==vertex)dfs(i,br+1);
        }
    }