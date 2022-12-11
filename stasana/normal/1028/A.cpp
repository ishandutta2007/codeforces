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

typedef int_fast64_t ll;
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

    int n, m;
    cin >> n >> m;
    pair<int, int> s;
    pair<int, int> f;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (input<char>() == 'W') {
                continue;
            }
            if (s.first == 0) {
                s.first = i;
                s.second = j;
            }
            f.first = i;
            f.second = j;
        }
    }
    cout << (s.first + f.first) / 2 << " " << (s.second + f.second) / 2;
    return 0;
}