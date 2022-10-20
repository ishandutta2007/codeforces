#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;


int a,b,n,t;
int da,db;
int mina,minb;


int used[1000][1000];

int dfs(int x,int y);

int main()
    {

    int sum;
    scanf("%d%d%d%d%d%d",&sum,&t,&a,&b,&da,&db);
    used[a][b]=1;
    dfs(a,b);
    int i;
    for(i=1;i<=sum;i++)
        {
        if(used[i][sum-i]==1)
            {
            printf("YES\n");
            return 0;
            }
        }
    //printf("here\n");
    if(a>=sum)
        {
        if((a-sum)%da==0 && (a-sum)/da<t)
            {
            printf("YES\n");
            return 0;
            }
        }
    if(b>=sum)
        {
        if((b-sum)%db==0&& (b-sum)/db<t)
            {
            printf("YES\n");
            return 0;
            }
        }
    if(sum==0)
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
    }


int dfs(int x,int y)
    {
    used[x][y]=1;
    int pr=x-da;
    if((a-pr)/da<t)
        {
        if(used[x-da][y]==0)dfs(x-da,y);
        }
    pr=y-db;
    if((b-pr)/db<t)
        {
        if(used[x][y-db]==0)dfs(x,y-db);
        }
    }