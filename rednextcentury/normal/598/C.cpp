#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
class Point
{
    public:
        long double x;
        long double y;
        Point(){}
        Point(long double xx, long double yy) : x(xx), y(yy) {}
        ~Point();
        inline friend ostream& operator<<(ostream& output, const Point& point)
        {
            output << "[" << point.x << ", " << point.y <<"]";
            return output;
        }
};
long double PI = 3.1415926535897932384626433832795;

Point::~Point() {;}


long double get_clockwise_angle(const Point& p)
{
    long double angle = 0.0;


    /*calculate angle and return it*/
    angle = -atan2(p.x,-p.y);
    return angle;
}
bool compare_points(const Point& a, const Point& b)
{
    return (get_clockwise_angle(a) < get_clockwise_angle(b));
}
Point a[1000000];
pair<long double,int> b[1000000];
int main ()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=Point(x,y);
        b[i]=MP(get_clockwise_angle(a[i]),i+1);
    }
    sort(b,b+n);
    for (int i=n;i<2*n;i++)
        b[i]=b[i-n];
    long double mn = 1e18;
    int best = -1;
    for (int i=1;i<2*n;i++)
    {

        long double d = min(abs(b[i].F - b[i-1].F),2*PI-abs(b[i].F - b[i-1].F));
        if (d < mn)
        {
            mn=d;
            best = i;
        }
    }
    cout<<b[best].second<<' '<<b[best-1].second<<endl;
}