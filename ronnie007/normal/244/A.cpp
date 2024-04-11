#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int n,k;
int a[100];
int used[1000];

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
    scanf("%d%d",&n,&k);
    int i;
    for(i=0;i<k;i++)
        {
        scanf("%d",&a[i]);
        used[a[i]]=1;
        }
    }


void solve()
    {
    int i;
    int j;
    int g;
    for(i=0;i<k;i++)
        {
        printf("%d",a[i]);
        g=1;
        for(j=1;j<=n*k;j++)
            {
            if(g==n)break;
            if(used[j]==0)
                {
                g++;
                used[j]=1;
                printf(" %d",j);
                }
            }
        printf("\n");
        }
    }