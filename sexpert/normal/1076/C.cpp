#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

int main()
{
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while(t--)
    {
        double d;
        cin >> d;
        if(abs(d - 1) < eps || abs(d - 2) < eps || abs(d - 3) < eps)
        {
            cout << "N\n";
            continue;
        }
        if(abs(d) < eps)
        {
            cout << "Y " << 0.0 << " " << 0.0 << endl;
            continue;
        }
        if(abs(d - 4) < eps)
        {
            cout << "Y " << 2.0 << " " << 2.0 << endl;
            continue;
        }
        double a = (d + sqrt(d*d - 4*d))*0.5;
        cout << "Y " << a << " " << d - a << endl;
    }    
}