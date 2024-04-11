// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n, i = 1;
    cin >> n;
    for (; n > i * i; ++i);
    cout << i + (n - 1) / i + 1 << endl;
}

int main() {
    start();
    solve();
    return 0;
}