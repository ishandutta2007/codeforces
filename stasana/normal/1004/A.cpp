#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;
typedef long double ld;

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    set<int> u;
    for (int i = 0; i < n; ++i) {
        if (u.find(a[i] + d) == u.end()) {
            u.insert(a[i] + d);
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (abs(a[j] - (a[i] + d)) < d) {
                    f = false;
                }
            }
            res += f;
        }
        if (u.find(a[i] - d) == u.end()) {
            u.insert(a[i] - d);
            bool f = true;
            for (int j = 0; j < n; ++j) {
                if (abs(a[j] - (a[i] - d)) < d) {
                    f = false;
                }
            }
            res += f;
        }
    }
    cout << res;
    return 0;
}