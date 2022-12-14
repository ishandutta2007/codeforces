#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    long double r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    long double d = hypot(x1-x2,y1-y2);
    long double R = (r+d)/2.0;
    if (d>=r)
    {
        cout<<x1<<' '<<y1<<' '<<r<<endl;
        return 0;
    }
    if (d<1e-5)
    {
        cout<<x1+R<<' '<<y1<<' '<<R<<endl;
        return 0;
    }
    long double X = x1*(R/d)+x2*(1-R/d);
    long double Y = y1*(R/d)+y2*(1-R/d);
    cout<<setprecision(10)<<fixed<<X<<' '<<Y<<' '<<R<<endl;
}