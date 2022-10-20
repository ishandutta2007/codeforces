#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;

int n;
int sm=0;

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
    int x;
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        sm+=x;
        }
    }


void solve()
    {
    int i;
    int br=0;
    for(i=1;i<=5;i++)
        {
        if((i+sm)%(n+1)!=1)br++;
        }
    printf("%d\n",br);
    }