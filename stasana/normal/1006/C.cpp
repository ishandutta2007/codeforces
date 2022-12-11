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
typedef uint64_t ull;
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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + input<ll>();
    }
    for (int i = 0; i <= n; ++i) {
        int left = i;
        int right = n + 1;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (a[i] > a[n] - a[mid]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        if (a[i] == a[n] - a[left]) {
            result = a[i];
        }
    }
    cout << result;
    return 0;
}