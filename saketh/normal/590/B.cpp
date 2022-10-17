#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double SX, SY;
double TX, TY;

double V_max, T;

double wx1, wy1;
double wx2, wy2;

bool go(double time) {
    double FX = TX, FY = TY;

    FX += min(time, T) * -wx1;
    FY += min(time, T) * -wy1;

    if (time > T) {
        FX += (time - T) * -wx2;
        FY += (time - T) * -wy2;
    }

    double dist = sqrt(pow(FX - SX, 2) + pow(FY - SY, 2));
    return dist < time * V_max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> SX >> SY >> TX >> TY;
    cin >> V_max >> T;

    cin >> wx1 >> wy1;
    cin >> wx2 >> wy2;

    double ans = 1;
    while (!go(ans)) ans *= 2;

    double lo = 0, hi = ans;

    for (int i = 0; i < 5000; i++) {
        double mi = (lo + hi) / 2;

        if (go(mi)) {
            hi = mi;
        }
        else lo = mi;
    }

    cout << hi << "\n";
}