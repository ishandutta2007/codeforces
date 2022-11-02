#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double fnd(double a,double v,double q)
{
    double t = 0;
    if (2.0*a*q>v*v)
    {
        t+=v/a;
        t+=(q-v*v/2.0/a)/v;
    }
    else
    {
        t+=sqrt(2.0*q/a);
    }
    return t;
}

int main()
{
    int n;
    double a,d;
    cin >> n >> a >> d;
    double tpr = 0;
    for (int i=0;i<n;i++)
    {
        double ti,vi;
        cin >> ti >> vi;
        ti+=fnd(a,vi,d);
        if (ti<tpr) ti = tpr;
        cout << fixed << setprecision(18) << ti << endl;
        tpr = ti;
    }
    return 0;
}