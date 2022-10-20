#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;




char g[50000];
char h[50000];
char a[50000];
char b[50000];

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
    gets(g);
    gets(h);
    }



void solve()
    {
    int i;
    int tp=0;
    for(i=0;i<strlen(g);i++)
        {
        if(g[i]!=':')
            {
            a[i]=g[i];
            }
        else a[i]=' ';
        }
    tp=0;
    for(i=0;i<strlen(h);i++)
        {
        if(h[i]!=':')
            {
            b[i]=h[i];
            }
        else b[i]=' ';
        }
    int x,y,z;
    int x1,y1,z1;
    sscanf(a,"%d%d%d",&x,&y,&z);
    sscanf(b,"%d%d%d",&x1,&y1,&z1);
    if(x>x1)
        {
        swap(x,x1);
        swap(y,y1);
        swap(z,z1);
        }
    if(x==x1 && y>y1)
        {
        swap(x,x1);
        swap(y,y1);
        swap(z,z1);
        }
    if(x==x1 && y==y1 && z>z1)
        {
        swap(x,x1);
        swap(y,y1);
        swap(z,z1);
        }

    ///printf("%d %d %d\n",x,y,z);
    ///printf("%d %d %d\n",x1,y1,z1);
    int br=0;
    while(x!=x1 || y!=y1 || z!=z1)
        {
        z++;
        br++;
        if(y==2 && z==29 && (x%4!=0 || x==1900))
            {
            y++;
            z=1;
            }
        if(y==2 && z==30 && (x%4==0 && x!=1900))
            {
            y++;
            z=1;
            }
        if(z==32)
            {
            y++;
            z=1;
            if(y==13){x++;y=1;}
            }
        if(z==31)
            {
            if(y==4 || y==6 || y==9 || y==11)
                {
                y++;
                z=1;
                }
            }
        ///printf("%d %d %d\n",x,y,z);
        ///system("pause");
        }
    printf("%d\n",br);
    }