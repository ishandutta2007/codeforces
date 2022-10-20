#include<fstream>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;


int x,y;


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
    scanf("%d%d",&x,&y);
    }


void solve()
    {
    int i,j;
    i=0;
    j=0;
    int dir=1;
    int br=0;
    int move=0;
    int dist=1;
    int br1=0;
    while(i!=x || j!=y)
        {
        if(dir==0)j--;
        if(dir==1)i++;
        if(dir==2)j++;
        if(dir==3)i--;
        //printf("%d %d\n",i,j);
        if(i==x && j==y)break;
        move++;
        if(move==dist)
            {
            br1++;
            dir=(dir+1)%4;
            if(br1==2)
                {
                dist++;
                br1=0;
                }
            move=0;
            br++;
            }
        }
    cout<<br<<"\n";
    }