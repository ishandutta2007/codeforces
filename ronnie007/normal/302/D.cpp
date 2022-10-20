#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

int n,d;
int x[128],y[128];
int a[128];
int v[128][128];


void input();
void solve();

int main()
    {
    input();
    solve();
    printf("%d\n",v[0][n-1]);
    return 0;
    }


void input()
    {
    int i;
    scanf("%d%d",&n,&d);
    for(i=1;i<n-1;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x[i],&y[i]);
        }
    }




void solve()
    {
    int i,j,k,p,q;
    for(i=1;i<n;i++)
        {
        for(j=0;j<i;j++)
            {
            p=abs(x[i]-x[j])+abs(y[i]-y[j]);
            v[i][j]=p*d-a[i];
            v[j][i]=p*d-a[j];
            }
        }
    for(k=0;k<n;k++)
        {

        for(i=0;i<n;i++)
            {

            for(j=0;j<n;j++)
                {

                if(v[i][j]>v[i][k]+v[k][j] && i!=j && j!=k && i!=k)v[i][j]=v[i][k]+v[k][j];
                }
            }
        }

    }