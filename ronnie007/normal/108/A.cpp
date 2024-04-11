#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
    {
    string a;
    cin>>a;
    int x,y,z,t;
    x=a[0]-'0';
    y=a[1]-'0';
    z=a[3]-'0';
    t=a[4]-'0';
    while(1)
        {
        t++;
        if(t==10)
            {
            t=0;
            z++;
            if(z==6)
                {
                y++;
                z=0;
                if(y==10)
                    {
                    y=0;
                    x++;
                    }
                if(y==4 && x==2)
                    {
                    x=0;
                    y=0;
                    }
                }
            }
        //printf("%d%d:%d%d\n",x,y,z,t);
        if(x==t && y==z)break;
        }
    printf("%d%d:%d%d\n",x,y,z,t);
    return 0;
    }