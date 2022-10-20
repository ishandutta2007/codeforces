#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;



int n;
string a;
int x,y;
int ex,ey;


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
    cin>>n>>x>>y>>ex>>ey;
    cin>>a;
    }



void solve()
    {
    int i;
    int difx,dify;
    difx=ex-x;
    dify=ey-y;
    int br=-2;
    for(i=0;i<n;i++)
        {
        if(a[i]=='E' && difx>0)difx--;
        if(a[i]=='N' && dify>0)dify--;
        if(a[i]=='W' && difx<0)difx++;
        if(a[i]=='S' && dify<0)dify++;
        if(difx==0 && dify==0){br=i;break;}
        }
    cout<<br+1<<"\n";
    }