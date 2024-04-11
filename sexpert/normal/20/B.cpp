#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cout << fixed << setprecision(9);

    ll a, b, c;
    cin >> a >> b >> c;
    if(a == 0) {
        if(b == 0) {
            cout << (c == 0 ? -1 : 0) << '\n';
            return 0;
        }
        cout << "1\n";
        cout << (double)(-c)/b << '\n';
        return 0;
    }

    ll d = b * b - 4LL * a * c;
    if(d < 0) {
        cout << "0\n";
        return 0;
    }
    if(d == 0) {
        cout << "1\n";
        cout << (double)(-b)/(2.0*a) << '\n';
        return 0;
    }
    cout << "2\n";
    vector<double> sols;
    sols.push_back((double)(-b - sqrtl(d))/(2.0*a));
    sols.push_back((double)(-b + sqrtl(d))/(2.0*a));
    sort(sols.begin(), sols.end());
    cout << sols[0] << '\n' << sols[1] << '\n';
}