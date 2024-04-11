#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;


int n,m,d;
int a[150][150];
int ost;
int b[100005];



void input();
void solve();
int f(int num);


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d%d%d",&n,&m,&d);
    int i,j;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            scanf("%d",&a[i][j]);
            }
        }
    }



void solve()
    {
    ost=a[0][0]%d;
    int i,j;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            if(a[i][j]%d!=ost)
                {
                printf("-1\n");
                return ;
                }
            }
        }
    int k;
    int sz=1;
    for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
            {
            b[sz]=a[i][j];
            sz++;
            }
        }
    sort(b,b+sz);
    int mid=(n*m/2);
    //printf("%d\n",mid);
    int ans=f(mid);
    if(ans>f(mid+1))ans=f(mid+1);
    printf("%d\n",ans);
    }


int f(int num)
    {
    int i,j;
    int ret=0;
    int h;
    for(i=1;i<=n*m;i++)
        {
        h=abs(b[num]-b[i]);
        ret+=h/d;
        }
    return ret;
    }