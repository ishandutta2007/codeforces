#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


int n,m;

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
    }
    
void solve()
    {
    int ans=3*n-m;
    if(ans<0)ans=0;
    printf("%d\n",ans);
    }