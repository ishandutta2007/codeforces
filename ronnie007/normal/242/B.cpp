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



void input();
void solve();

int n;
int a[100007];
int b[100007];
int mx1=0;



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
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&a[i],&b[i]);
        if(mx1<b[i]-a[i])mx1=b[i]-a[i];
        }
    }

void solve()
    {
    int i;
    int mn=1000000000;
    int mx=0;
    for(i=0;i<n;i++)
        {
        if(mx<b[i])mx=b[i];
        if(mn>a[i])mn=a[i];
        }
    for(i=0;i<n;i++)
        {
        if(b[i]-a[i]==mx1)
            {
            if(a[i]==mn && b[i]==mx)
                {
                printf("%d\n",i+1);
                return ;
                }
            }
        }
    printf("-1\n");
    }