#include<iostream>
#include<stdio.h>
using namespace std;


int n;
int x[10050];
int y[10050];
int br=0;
int br1=0;


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
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&x[i],&y[i]);
        }
    }


void solve()
    {
    int i;
    for(i=0;i<n;i++)
        {
        if(x[i]==1)br++;
        if(y[i]==1)br1++;
        }
    int ans=0;
    if(br<=n/2)ans+=br;
    else ans+=(n-br);
    if(br1<=n/2)ans+=br1;
    else ans+=(n-br1);
    printf("%d\n",ans);
    }