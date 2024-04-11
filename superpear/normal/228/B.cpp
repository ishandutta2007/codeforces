#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>

#define maxlongint 2147483647
#define biglongint 2139062143


using namespace std;

int m1,n1,m2,n2,cc,maxc,xans,yans,a[55][55],b[55][55];
char ch;

int main()
{
    cin>>m1>>n1;scanf("%c",&ch);
    for (int i=1;i<=m1;i++)
    {
        for (int j=1;j<=n1;j++)
        {
            scanf("%c",&ch);
            a[i][j]=ch-48;
        }
        scanf("%c",&ch);
    }
    cin>>m2>>n2;scanf("%c",&ch);
    for (int i=1;i<=m2;i++)
    {
        for (int j=1;j<=n2;j++)
        {
            scanf("%c",&ch);
            b[i][j]=ch-48;
        }
        scanf("%c",&ch);
    }
    maxc=-1;xans=0;yans=0;
    for (int x=-m1-m2;x<=m1+m2;x++)
        for (int y=-n1-n2;y<=n1+n2;y++)
        {
            cc=0;
            for (int i=1;i<=m2;i++)
            {
                if (i-x>m1) break;
                if (i-x<1) continue;
                for (int j=1;j<=n2;j++)
                {
                    if (j-y>n1) break;
                    if (j-y<1) continue;
                    cc+=b[i][j]*a[i-x][j-y];
                }
            }
            if (cc>maxc)
            {
                maxc=cc;xans=x;yans=y;
            }
        }
    cout<<xans<<" "<<yans<<endl;

    return 0;
}