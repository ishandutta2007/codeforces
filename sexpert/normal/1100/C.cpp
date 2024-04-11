    #include <bits/stdc++.h>
    using namespace std;
    typedef long double ld;
     
    const ld PI = acos(-1);
     
    int main() {
        ld n, r;
        cin >> n >> r;
        ld x = (1.0 - cos(2*PI/n));
        ld rx = r*x;
        ld R = (rx + sqrt(2.0*r*rx));
        R /= (2.0 - x);
        cout << fixed << setprecision(20) << R << endl;
    }