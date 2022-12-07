#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#define MAXN 25100
using namespace std;
double curx;
bool flag;
struct Car
{
    double x, y, dx, dy, s;
    Car()
    {
        x = y = dx = dy = s = 0;
    }
    Car(double xx, double yy, double ddx, double ddy, double ss)
    {
        x = xx; y = yy; dx = ddx; dy = ddy; s = ss;
    }
    double Slope()
    {
        return dy/dx;
    }
    double Intercept()
    {
        return y - x*Slope();
    }
    double Speed()
    {
        return dx*s/sqrt(dx*dx+dy*dy);
    }
    double Eval(double xx)
    {
        return Slope()*xx + Intercept();
    }
    bool operator <(const Car &rhs) const
    {
        Car a = Car(x, y, dx, dy, s);
        Car b = Car(rhs.x, rhs.y, rhs.dx, rhs.dy, rhs.s);
        if(abs(a.Eval(curx)-b.Eval(curx)) > 1e-9)
        {
            return a.Eval(curx) < b.Eval(curx);
        }
        else
        {
            return a.x < b.x;
        }
    }
};
struct Event
{
    double x; Car l; bool tp;
    Event()
    {
        l = Car(); x = 0; tp = false;
    }
    Event(Car ll, double t, bool ttp)
    {
        l = ll; tp = ttp;
        if(ttp)
        {
            if(ll.dx > 0)
            {
                x = ll.x + t*ll.Speed();
            }
            else
            {
                x = ll.x;
            }
        }
        else
        {
            if(ll.dx < 0)
            {
                x = ll.x + t*ll.Speed();
            }
            else
            {
                x = ll.x;
            }
        }
    }
    bool operator <(const Event &rhs) const
    {
        return x < rhs.x;
    }
};
bool isect(Car a, Car b, double t) //do cars a and b collide by time t?
{
    if(a.Slope() == b.Slope())
    {
        if(abs((b.y-a.y)/(b.x-a.x)-a.Slope()) < 1e-9)
        {
            double ta = (b.x-a.x)/a.Speed();
            double tb = (a.x-b.x)/b.Speed();
            if(ta >= 0 && ta <= t)
            {
                return true;
            }
            else if(tb >= 0 && tb <= t)
            {
                return true;
            }
            else if(ta >= 0 && tb >= 0 && 1/(1/ta+1/tb) <= t)
            {
                return true;

            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        double ix = (b.Intercept()-a.Intercept())/(a.Slope()-b.Slope());
        double ta = (ix-a.x)/a.Speed();
        double tb = (ix-b.x)/b.Speed();
        if(ta >= 0 && tb >= 0 && ta <= t && tb <= t)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool diff(double a, double b)
{
    if(b-a < 1e-7)
    {
        return false;
    }
    else if((b-a)/a < 1e-7)
    {
        return false;
    }
    return true;
}
int N;
Car c[MAXN];
double lbound, hbound, avg;
bool judge(double t)
{
    vector<Event> p;
    multiset<Car> s;
    multiset<Car>::iterator it, it2;
    for(int i=0; i<N; i++)
    {
        p.push_back(Event(c[i], t, false));
        p.push_back(Event(c[i], t, true));
    }
    sort(p.begin(), p.end());
    for(int i=0; i<p.size(); i++)
    {
        curx = p[i].x;
        if(p[i].tp) // remove car p[i] from s
        {
            it = s.lower_bound(p[i].l);
            it2 = it;
            ++it;
            s.erase(it2);
            if(it != s.begin())
            {
                it2 = it;
                --it2;
                if(it != s.end() && isect(*it, *it2, t))
                {
                    return true;
                }
            }
        }
        else //add car p[i] to s
        {
            s.insert(p[i].l);
            it = s.lower_bound(p[i].l);
            it2 = it;
            ++it2;
            if(it2 != s.end())
            {
                if(isect(*it, *it2, t))
                {
                    return true;
                }
            }
            it2 = it;
            if(it != s.begin())
            {
                --it2;
                if(isect(*it, *it2, t))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>c[i].x>>c[i].y>>c[i].dx>>c[i].dy>>c[i].s;
    }
    hbound = 1e12;
    if(!judge(hbound))
    {
        cout<<"No show :("<<endl;
        return 0;
    }
    while(diff(lbound, hbound))
    {
        avg = (lbound + hbound)/2;
        if(judge(avg))
        {
            hbound = avg;
        }
        else
        {
            lbound = avg;
        }
    }
    cout<<fixed<<setprecision(7)<<avg<<endl;
}