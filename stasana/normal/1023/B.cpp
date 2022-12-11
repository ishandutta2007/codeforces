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

    ll n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n + n - 1 < k) {
        cout << 0;
        return 0;
    }
    ll right = min(n, k - 1);
    ll left = k - right;
    cout << (right - left + 1) / 2;
    return 0;
}