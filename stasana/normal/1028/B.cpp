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

    for (int i = 0; i < 1000; ++i) {
        cout << "6";
    }
    cout << endl;
    for (int i = 0; i < 999; ++i) {
        cout << "3";
    }
    cout << 4;

    return 0;
}