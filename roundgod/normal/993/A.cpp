/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 00:38:41
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,minx,maxx,miny,maxy,minx2,maxx2,miny2,maxy2;
bool check1(int x,int y)
{
    return (x>=minx&&x<=maxx&&y>=miny&&y<=maxy);
}
bool check2(int x,int y)
{
    int nx=x+y,ny=x-y;
    return (nx>=minx2&&nx<=maxx2&&ny>=miny2&&ny<=maxy2);
}
int main()
{
    int p,q;
    minx=miny=minx2=miny2=INF;
    maxx=maxy=maxx2=maxy2=-INF;
    for(int i=0;i<4;i++)
    {
        scanf("%d%d",&p,&q);
        minx=min(minx,p);maxx=max(maxx,p);miny=min(miny,q);maxy=max(maxy,q);
    }
    for(int i=0;i<4;i++)
    {
        scanf("%d%d",&p,&q);
        int np=p+q,nq=p-q;
        minx2=min(minx2,np);maxx2=max(maxx2,np);miny2=min(miny2,nq);maxy2=max(maxy2,nq);
    }
    for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
        {
            if(check1(i,j)&&check2(i,j))
            {
                puts("Yes");
                return 0;
            }
        }
    puts("No");
    return 0;
}