#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100005

struct Point
{
    int x,id;
}p[MAX_N];
int n,posi[MAX_N],maxi[MAX_N],mini[MAX_N];

bool comp(Point a,Point b) {return a.x<b.x;}

inline void Init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&posi[i]);
}

inline void Output()
{
    for (int i=1;i<=n;i++) printf("%d %d\n",mini[i],maxi[i]);
}

inline void Solve()
{
    if (n==1)
    {
        puts("0 0");
        return;
    }
    for (int i=1;i<=n;i++) p[i]=(Point){posi[i],i};
    sort(p+1,p+n+1,comp);
    for (int i=1;i<=n;i++)
    {
        maxi[p[i].id]=max(p[i].x-p[1].x,p[n].x-p[i].x);
        if (i==1) mini[p[i].id]=p[i+1].x-p[i].x;
        else if (i==n) mini[p[i].id]=p[i].x-p[i-1].x;
        else mini[p[i].id]=min(p[i].x-p[i-1].x,p[i+1].x-p[i].x);
    }
    Output();
}

int main()
{
    Init();
    Solve();
    
	return 0;
}