#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Point
{
    int x, y;
    Point()
    {
        x=y=0;
    }
    Point(int xx, int yy)
    {
        x=xx;
        y=yy;
    }
    bool operator <(const Point &rhs) const
    {
        if(x!=rhs.x)
        {
            return x<rhs.x;
        }
        else
        {
            return y<rhs.y;
        }
    }
};
Point a[3];
map<Point, bool> m;
vector<Point> v;
Point p;
int Area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    return abs(x1*y2+x2*y3+x3*y4+x4*y1-x2*y1-x3*y2-x4*y3-x1*y4);
}
int main()
{
    for(int i=0; i<3; i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    sort(a, a+3);
    do{
        p=Point(a[1].x-a[0].x+a[2].x, a[1].y-a[0].y+a[2].y);
        if(!m[p])
        {
            m[p]=true;
            v.push_back(p);
        }
    }while(next_permutation(a, a+3));
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
}