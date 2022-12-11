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
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (value % 2 == 0) {
            cout << value - 1 << " ";
        }
        else {
            cout << value << " ";
        }
    }
    return 0;
}