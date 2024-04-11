#include<iostream>
#include<math.h>
#include<cstring>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef __int64 ll;
struct point{
    ll da,db,x,y;
}p[2000+10];
bool cmp(point a,point b)
{
    return a.da<b.da;
}
int main()
{
    int n;cin>>n;
    ll x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
    ll r1,r2;
    double res=1e16;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].da = (p[i].x-x1)*(p[i].x-x1)+(p[i].y-y1)*(p[i].y-y1);
        p[i].db = (p[i].x-x2)*(p[i].x-x2)+(p[i].y-y2)*(p[i].y-y2);
    }
    p[0].da=0;
    sort(p+1,p+1+n,cmp);
    for(int i=0;i<=n;i++)
    {
        ll max_db=0;
        for(int j=i+1;j<=n;j++)
        {
            if(p[j].db>max_db) max_db=p[j].db;
        }
        if(p[i].da+max_db<res)
        {
            res=p[i].da+max_db;
        }
    }

    cout<<(ll)res<<endl;
    return 0;
}