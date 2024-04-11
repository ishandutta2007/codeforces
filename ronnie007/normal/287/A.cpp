#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int n;
string a[8];

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
    int i;
    for(i=0;i<4;i++)
        {
        cin>>a[i];
        }
    }


void solve()
    {
    int br=0;

    int i,j;
    for(i=0;i<3;i++)
        {
        for(j=0;j<3;j++)
            {
            br=0;
            if(a[i][j]=='.')br++;
            if(a[i+1][j]=='.')br++;
            if(a[i][j+1]=='.')br++;
            if(a[i+1][j+1]=='.')br++;
            if(br==1 || br==3 || br==0 || br==4)
                {
                printf("YES\n");
                return ;
                }
            }
        }
    printf("NO\n");
    }