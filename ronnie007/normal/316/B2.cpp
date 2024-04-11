#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;



vector < int > v;

int n;
int x;
int a[3270];
int used[3270];
int dp[3270];
int bplace=-1;
int plc;


void input();
void solve();
void f(int vertex);


int main()
    {
    input();
    solve();
    return 0;
    }




void input()
    {
    scanf("%d%d",&n,&x);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    }


void solve()
    {
    int i,j;
    int lstplc;
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
            {
            if(a[j]==i)break;
            }
        plc=0;
        lstplc=bplace;
        if(used[i]==0 && j==n+1)
            {
            f(i);
            if(bplace!=-1 && lstplc==-1){bplace=plc-bplace+1;continue;}
            v.push_back(plc);
            }
        }
    dp[0]=1;
    int m=v.size();
    for(i=0;i<m;i++)
        {
        ///printf("%d\n",v[i]);
        for(j=0;j<=n;j++)
            {
            if(dp[j]==1 && dp[j+v[i]]==0){dp[j+v[i]]=2;}
            }
        for(j=0;j<=n;j++)
            {
            if(dp[j]==2)dp[j]=1;
            }
        }
    for(i=0;i<=n;i++)
        {
        if(dp[i]==1)printf("%d\n",i+bplace);
        }
    }



void f(int vertex)
    {
    plc++;
    used[vertex]=1;
    if(vertex==x){bplace=plc;}
    if(a[vertex]==0)return ;
    f(a[vertex]);
    }