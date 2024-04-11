#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int n;
vector < int > v[50007];
int oldc,newc;

int dir[50007];


void input();
void solve();
void dfs(int vertex);


int main()
    {
    input();
    solve();
    return 0;
    }

void input()
    {
    scanf("%d",&n);
    scanf("%d%d",&oldc,&newc);
    int i;
    int p;
    for(i=1;i<=n;i++)
        {
        if(i==oldc)continue;
        scanf("%d",&p);
        v[p].push_back(i);
        v[i].push_back(p);
        }
    }

void solve()
    {
    dfs(newc);
    int i;
    for(i=1;i<=n;i++)
        {
        if(i==newc)continue;
        printf("%d ",dir[i]);
        }
    printf("\n");
    }
void dfs(int vertex)
    {
    int i;
    int sz=v[vertex].size();
    for(i=0;i<sz;i++)
        {
        if(dir[v[vertex][i]]==0)
            {
            dir[v[vertex][i]]=vertex;
            dfs(v[vertex][i]);
            }
        }
    }