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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll second = 0;
    vector<int> f(100001);
    vector<int> s(100001);
    for (int i = 0; i < n; ++i) {
        if (s[a[i]] == 0) {
            ++second;
        }
        ++s[a[i]];
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ++f[a[i]];
        --s[a[i]];
        if (s[a[i]] == 0) {
            --second;
        }
        if (f[a[i]] == 1) {
            res += second;
        }
    }
    cout << res;
    return 0;
}