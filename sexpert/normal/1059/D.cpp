#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;

struct punto
{
    double x, y;
    punto(double x = 0, double y = 0) : x(x), y(y){}
};

vector<punto> pts;

double rad(double pos)
{
    vector<punto> ints;
    double ymax = 0.0;
    for(punto p : pts)
    {
        double newy = ((pos - p.x)*(pos - p.x) + p.y*p.y)/(2.0*p.y);
        ymax = max(ymax, newy);
    }
    return ymax;
}

double ts()
{
    double low = -1e10;
    double high = 1e10;
    for(int i = 0; i < 500; i++)
    {
        double trd = (high - low)/3.0;
        if(rad(low + trd) < rad(low + 2.0*trd))
            high = low + 2.0*trd;
        else
            low = low + trd;
    }
    return rad(low);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    bool hasPos = false, hasNeg = false;
    for(int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        if(y > 0)
            hasPos = true;
        if(y < 0)
            hasNeg = true;
        pts.push_back(punto(x, abs(y)));
    }
    if(hasPos && hasNeg)
    {
        cout << -1 << endl;
        return 0;
    }
    /*for(punto p : pts)
        cout << p.x << " " << p.y << endl;*/
    //cout << rad(0.5) << endl;
    cout << fixed << setprecision(10) << ts() << endl;
}