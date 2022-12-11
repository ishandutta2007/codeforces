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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (n - k > 0 && s[i] == '(') {
            ++k;
            ++k;
            s[i] = ' ';
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] == '(') {
            ++cnt;
            cout << "(";
        }
        if (s[i] == ')') {
            if (cnt > 0) {
                --cnt;
                cout << ")";
            }
        }
    }

    return 0;
}