#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
struct Point
{
    ll x, y;
    Point()
    {
        x = y = 0;
    }
    Point(ll xx, ll yy)
    {
        x = xx; y = yy;
    }
    bool operator <(const Point &rhs) const
    {
        if(x >= 0 && rhs.x < 0)
        {
            return true;
        }
        else if(rhs.x >= 0 && x < 0)
        {
            return false;
        }
        else if(x == 0)
        {
            return y < 0;
        }
        else if(rhs.x == 0)
        {
            return rhs.y > 0;
        }
        else
        {
            return y*rhs.x < x*rhs.y;
        }
    }
};
ll N;
vector<Point> u, v;
ll tot;
ll solve(int cur)
{
    v.clear();
    for(int i=0; i<N; i++)
    {
        if(i != cur)
        {
            v.push_back(Point(u[cur].x-u[i].x, u[cur].y-u[i].y));
        }
    }
    sort(v.begin(), v.end());
    int counter = 1;
    ll c;
    ll ans = 0;
    for(int i=0; i<N-1; i++)
    {
        while(true)
        {
            if(counter > i && ((v[i] < Point(0, 1) && v[counter] < Point(-v[i].x, -v[i].y))||(!(v[i] < Point(0, 1)))))
            {
                ++counter;
                counter %= (N-1);
            }
            else if(counter < i && (v[counter] < Point(0, 1) && Point(-v[counter].x, -v[counter].y) < v[i]))
            {
                ++counter;
            }
            else
            {
                break;
            }
        }
        c = (counter-i+N-2)%(N-1);
        ans += (c*(c-1)/2);
    }
    return (N-1)*(N-2)*(N-3)/6-ans;
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        u.push_back(Point());
        cin>>u[i].x>>u[i].y;
    }
    for(int i=0; i<N; i++)
    {
        tot += solve(i);
    }
    cout<<tot*(N-4)/2<<endl;
}