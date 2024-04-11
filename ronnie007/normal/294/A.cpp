#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int n;
int a[150];



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
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    }

void solve()
    {
    int i;
    int m;
    int x,y;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&x,&y);
        if(x>1){a[x-1]+=(y-1);}
        if(x<n){a[x+1]+=(a[x]-y);}
        a[x]=0;
        }
    for(i=1;i<=n;i++)
        {
        printf("%d\n",a[i]);
        }
    }