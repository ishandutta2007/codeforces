#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int n,m;
int a[150];
int v[150][150];


void input();
void solve();


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    int x,y;
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&x,&y);
        v[x-1][y-1]=1;
        v[y-1][x-1]=1;
        }
    }


void solve()
    {
    int i,j,t;
    long long mn=1000000000;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            {
            for(t=0;t<n;t++)
                {
                if(v[i][j]==1 && v[i][t]==1 && v[j][t]==1)
                    {
                    if(mn>a[i]+a[j]+a[t])mn=a[i]+a[j]+a[t];
                    }
                }
            }
        }
    if(mn!=1000000000)cout<<mn<<"\n";
    else cout<<"-1\n";
    }