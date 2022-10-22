/*
ZDRAVSTVUYTE
ESLI VI HOTITE MENYA VZLOMAT'
YA VAM SRAZU SKAZHU
TUT BAGOV NETU
UDACHNOGO VZLOMA
SPASIBO ZA VNIMANIE
*/

#include <bits/stdc++.h>
#define ll long long

const int INF = 1e9 + 7;
const long double EPS = 1e-8;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <long double> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long double l = 0, r = INF;
    while (r - l > EPS) {
        long double mid = (l + r) / 2;
        long double l1 = x[0] - v[0] * mid;
        long double r1 = x[0] + v[0] * mid;
        bool fl = 0;
        for (int i = 1; i < n; i++) {
            long double l2 = x[i] - v[i] * mid;
            long double r2 = x[i] + v[i] * mid;
            if (l2 - r1 > EPS) {
                fl = 1;
                break;
            } else if (l1 - r2 > EPS) {
                fl = 1;
                break;
            }
            l1 = max(l2, l1);
            r1 = min(r2, r1);
        }
        if (fl) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout.precision(20);
    cout << l;
}