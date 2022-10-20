#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int n,m;
int a[200007];
int f;
int p;


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
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        if(a[i]==1)
            {
            f++;
            }
        else p++;
        }
    }

void solve()
    {
    int i;
    int x,y;
    int k;
    int g;
    int mn;
    if(f>p)mn=p;
    else mn=f;
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&x,&y);
        if(2*mn>=(y-x+1) && (y-x+1)%2==0)printf("1\n");
        else printf("0\n");
        }
    }