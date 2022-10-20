#include<fstream>
#include<iostream>
#include<stdio.h>
using namespace std;

int n,m;

void input();
void solve();


int main()
    {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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
    if(n>=m)
        {
        while(n>0 || m>0)
            {
            if(n>0){printf("B");n--;}
            if(m>0){printf("G");m--;}
            }
        }
    else
        {
        while(n>0 || m>0)
            {
            if(m>0){printf("G");m--;}
            if(n>0){printf("B");n--;}
            }
        }
    printf("\n");
    }