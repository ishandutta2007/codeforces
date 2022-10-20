#include<iostream>
#include<stdio.h>
using namespace std;


int used[107];

int main()
    {
    int n;
    int speed[107];
    int ram[107];
    int hdd[107];
    int price[107];
    int x;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d%d%d%d",&speed[i],&ram[i],&hdd[i],&price[i]);
        }
    for(i=0;i<n;i++)
        {
        if(used[i]==1)continue;
        for(j=0;j<n;j++)
            {
            if(speed[j]>speed[i] && ram[j]>ram[i] && hdd[j]>hdd[i]){used[i]=1;break;}
            }
        }
    int mn=1000000;
    int ind=-1;
    for(i=0;i<n;i++)
        {
        if(used[i]==0)
            {
            if(mn>price[i])
                {
                mn=price[i];
                ind=i;
                }
            }
        }
    printf("%d\n",ind+1);
    return 0;
    }