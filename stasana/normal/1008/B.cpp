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

bool check(char ch) {
    string data = "aeoiu";
    for (auto j : data) {
        if (j == ch) {
            return true;
        }
    }
    return false;
}

int main() {
    start();
    vector<int> a;
    a.push_back(1e9 + 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int mn = input<int>();
        int mx = input<int>();
        if (mn > mx) {
            swap(mn, mx);
        }
        if (mx > a.back()) {
            if (mn > a.back()) {
                cout << "NO";
                return 0;
            }
            a.push_back(mn);
        }
        else {
            a.push_back(mx);
        }
    }
    cout << "YES";
    return 0;
}