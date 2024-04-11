#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<stack>
#include<string>
#include<map>
using namespace std;

int x,y,a,b;

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
    scanf("%d%d%d%d",&x,&y,&a,&b);
    }

void solve()
    {
    int br=0;
    int i,j;
    for(i=a;i<=x;i++)
        {
        for(j=b;j<i;j++)
            {
            if(j>y || j>=i)break;
            br++;
            }
        }
    printf("%d\n",br);
    for(i=a;i<=x;i++)
        {
        for(j=b;j<i;j++)
            {
            if(j>y || j>=i)break;
            printf("%d %d\n",i,j);
            }
        }
    }