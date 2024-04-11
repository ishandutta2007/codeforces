#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int a[5][5];
int b[5][5];

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
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            scanf("%d",&b[i][j]);
            b[i][j]=b[i][j]%2;
            }
        }
    }


void solve()
    {
    int i,j;
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            a[i][j]=1;
            }
        }
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            if(b[i][j]==1)
                {
                a[i][j]=1-a[i][j];
                if(i-1>=0)
                    {
                    a[i-1][j]=1-a[i-1][j];
                    }
                if(i+1<3)
                    {
                    a[i+1][j]=1-a[i+1][j];
                    }
                if(j-1>=0)
                    {
                    a[i][j-1]=1-a[i][j-1];
                    }
                if(j+1<3)
                    {
                    a[i][j+1]=1-a[i][j+1];
                    }
                }
            }
        }
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            printf("%d",a[i][j]);
            }
        printf("\n");
        }
    }