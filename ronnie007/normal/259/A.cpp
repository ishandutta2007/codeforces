#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

char a[15][15];

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
    int i,j;
    for(i=0;i<8;i++)
        {
        for(j=0;j<8;j++)
            {
            cin>>a[i][j];
            }
        }
    }


void solve()
    {
    int i;
    int j;
    for(i=0;i<8;i++)
        {
        for(j=0;j<7;j++)
            {
            if(a[i][j]==a[i][j+1])
                {
                printf("NO\n");
                return ;
                }
            }
        }
    printf("YES\n");
    }