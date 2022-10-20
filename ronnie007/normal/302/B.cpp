#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;


int n;
int m;
long long y=0;
int p;

int t[200007];
int c[200007];

int x[200005];


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
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&c[i],&t[i]);
        }
    }



void solve()
    {
    int i;
    int lst=0;
    int k=0;
    for(i=0;i<m;i++)
        {
        scanf("%d",&x[i]);
        }
    i=0;
    while(i<n)
        {
        if(k==0)y+=t[i]*c[i];
        k=1;
        if(y>=x[lst] && lst<m)
            {
            printf("%d\n",i+1);
            lst++;
            }
        else {i++;k=0;}
        }
    }