#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x,y,id;
};
bool can(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
     long long s = (y2 - y1 ) * x3 + (x1 - x2) * y3 + (x2 * y1 - x1 * y2);
     return s!=0;
}
long long dist[1000001];
bool comp(node aa,node bb)
{
    return dist[aa.id]<dist[bb.id];
}
node a[1000000];
int main()
{
    long long n;
    cin>>n;
    long long fx,fy;
    cin>>fx>>fy;
    for (long long i=1;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].id=i+1;
        dist[i+1]=(fx-a[i].x)*(fx-a[i].x)+(fy-a[i].y)*(fy-a[i].y);
    }
    long long b=1,c=1;
    sort(a+1,a+n,comp);

    b=a[1].id;
    for (long long i=2;i<n;i++)
    {
        if (can(a[1].x,a[1].y,fx,fy,a[i].x,a[i].y))
        {
            cout<<1<<" "<<b<<" "<<a[i].id<<endl;
            return 0;
        }
    }
}