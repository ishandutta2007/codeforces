#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef int_fast64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}



int main() {
    start();

    ll n, d;
    cin >> n >> d;
    int m = input<int>();
    for (int i = 0; i < m; ++i) {
        int x = input<int>(); 
        int y = input<int>();
        if (y < -x + d) {
            cout << "NO" << endl;
            continue;
        }
        if (y > x + d) {
            cout << "NO" << endl;
            continue;
        }
        if (y < x - d) {
            cout << "NO" << endl;
            continue;
        }
        if (y > -x + 2 * n - d) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}