// Megumin top

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const ld PI = 3.14159265358979323846;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n, r;
    cin >> n >> r;
    cout << fixed << setprecision(12) << (r * sin(PI / n)) / (1 - sin(PI / n));
}

int main() {
    start();
    solve();
    return 0;
}