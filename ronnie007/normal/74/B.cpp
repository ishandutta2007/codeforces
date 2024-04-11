#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    int n,x,y;
    int dir;
    string dir1,dir2;
    string t;
    int i;
    cin>>n>>x>>y;
    cin>>dir1>>dir2;
    cin>>t;
    if(dir2[0]=='h')dir=-1;
    else dir=1;

    for(i=0;i<t.size()-1;i++)
        {
        if(y==1)dir=1;
        if(y==n)dir=-1;
        if(t[i]=='0')
            {
            if(dir==-1)
                {
                if(x>1)x--;
                }
            else
                {
                if(x<n)x++;
                }
            y+=dir;
            if(x==y){printf("Controller %d\n",i+1);return 0;}
            }
        else
            {
            y+=dir;
            if(dir==1)x=1;
            else x=n;
            if(x==y){printf("Controller %d\n",i+1);return 0;}
            }
        }
    printf("Stowaway\n");
    return 0;
    }