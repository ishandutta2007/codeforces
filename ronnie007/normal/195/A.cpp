#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int a,b,c;

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
    scanf("%d%d%d",&a,&b,&c);
    }


void solve()
    {
    int i;
    for(i=1;i<10000000;i++)
        {
        if(b*i+c*b>=c*a)
            {
            printf("%d\n",i);
            return ;
            }
        }
    }