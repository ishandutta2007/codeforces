#include<iostream>
#include<stdio.h>
using namespace std;


int n;

void input();



int main()
    {
    input();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    int x,y,z;
    int br=0,br1=0;
    for(i=0;i<n;i++)
        {
        br=0;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)br++;
        if(y==1)br++;
        if(z==1)br++;
        if(br>=2)br1++;
        }
    printf("%d\n",br1);
    }