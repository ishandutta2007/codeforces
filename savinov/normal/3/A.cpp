#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dist(int x1,int y1,int x2,int y2)
{
    return -min(abs(x1-x2),abs(y1-y2))+abs(x1-x2)+abs(y1-y2);
}

void prnt(int i,int j)
{
    if (i==-1&&j==-1) puts("LD");
    if (i==1&&j==-1) puts("RD");
    if (i==0&&j==-1) puts("D");
    if (i==-1&&j==1) puts("LU");
    if (i==1&&j==1) puts("RU");
    if (i==0&&j==1) puts("U");
    if (i==-1&&j==0) puts("L");
    if (i==1&&j==0) puts("R");
}

int main()
{
    char x1,y1,x2,y2;
    x1=getchar()-'a';
    y1=getchar()-'0'-1;
    getchar();
    x2=getchar()-'a';
    y2=getchar()-'0'-1;

    printf("%i\n",dist(x1,y1,x2,y2));
    while (x1!=x2||y1!=y2)
    {
        int mindist=100;
        for (int i=-1;i<=1;i++)
        {
            for (int j=-1;j<=1;j++)
            {
                if ((i!=0||j!=0)&&(x1+i>=0&&x1+i<8&&y1+j>=0&&y1+j<8)) mindist=min(mindist,dist(x1+i,y1+j,x2,y2));
            }
        }
        bool flag=true;
        for (int i=-1;i<=1&&flag;i++)
        {
            for (int j=-1;j<=1&&flag;j++)
            {
                if ((i!=0||j!=0)&&(x1+i>=0&&x1+i<8&&y1+j>=0&&y1+j<8)){
                if (mindist==dist(x1+i,y1+j,x2,y2))
                {
                    prnt(i,j);
                    flag=false;
                    x1+=i;
                    y1+=j;
                }
                }
            }
        }
    }
    return 0;
}