#include<iostream>
#include<stdio.h>
using namespace std;


int a[7][7];

int main()
    {
    int i,j,in;
    int m;
    scanf("%d",&m);
    int x,y;
    for(i=0;i<m;i++)
        {
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
        }


    for (i=1;i<=5;i++)
        {
        for (j=i+1;j<=5;j++)
            {
            for (in=j+1;in<=5;in++)
                {
                if ( a[i][j]==a[i][in] && a[i][in]==a[j][in]  )
                    {
                    printf("WIN\n");
                    return 0;
                    }
                }
            }
        }

    printf("FAIL\n");
    return 0;
    }