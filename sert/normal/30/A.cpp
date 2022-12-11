#include <string>
#include <fstream>;
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

const long double malo = 1e-14;

long long a, b, n, cur;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> a >> b >> n;
    for (long long x = -1000; x <= 1000; x++) {
        cur = a;
        for (int i = 0; i < n; i++) {
            cur = cur * x;
            if (abs(cur) > abs(b))
                break;
        }
        if (cur == b) {
            cout << x;
            return 0;
        }
    }
    cout << "No solution\n";
}