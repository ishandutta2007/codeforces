#include<iostream>
#include<stdio.h>
using namespace std;


int used[1007][1007];

int main()
    {
    int n,m;
    int x,y;
    int i;
    int g[100007];
    int p[100007];
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        {
        scanf("%d%d",&g[i],&p[i]);
        }
    for(i=1;i<=m;i++)
        {
        x=g[i]-1;
        y=p[i]-1;
        if(x>=2)
            {
            used[x-2][y]++;
            if(used[x-2][y]==9)
                {
                printf("%d\n",i);
                return 0;
                }
            if(y>=1)
                {
                used[x-2][y-1]++;
                if(used[x-2][y-1]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
            if(y>=2)
                {
                used[x-2][y-2]++;
                if(used[x-2][y-2]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
            }
        if(x>=1)
            {
            used[x-1][y]++;
            if(used[x-1][y]==9)
                {
                printf("%d\n",i);
                return 0;
                }
            if(y>=1)
                {
                used[x-1][y-1]++;
                if(used[x-1][y-1]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
            if(y>=2)
                {
                used[x-1][y-2]++;
                if(used[x-1][y-2]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
            }
            used[x][y]++;
            if(used[x][y]==9)
                {
                printf("%d\n",i);
                return 0;
                }
            if(y>=1)
                {
                used[x][y-1]++;
                if(used[x][y-1]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
            if(y>=2)
                {
                used[x][y-2]++;
                if(used[x][y-2]==9)
                    {
                    printf("%d\n",i);
                    return 0;
                    }
                }
        }
    printf("-1\n");
    return 0;
    }