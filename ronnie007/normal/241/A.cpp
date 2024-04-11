#include<iostream>
#include<stdio.h>
using namespace std;



int m,k;
int d[1050];
int s[1050];


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
    scanf("%d%d",&m,&k);
    int i;
    for(i=0;i<m;i++)
        {
        scanf("%d",&d[i]);
        }
    for(i=0;i<m;i++)
        {
        scanf("%d",&s[i]);
        }
    }


void solve()
    {
    int i;
    int br=0;
    int fuel=0;
    i=0;
    int mx=0;
    int br1=0;
    while(i<=m)
        {
        if(mx<s[i])mx=s[i];
        if(br1==0){fuel+=s[i];br1=1;}
        if(fuel>=d[i])
            {
            fuel-=d[i];
            br+=d[i];
            i++;
            br1=0;
            }
        else
            {
            br+=k;
            fuel+=mx;
            }
        }
    printf("%d\n",br);
    }