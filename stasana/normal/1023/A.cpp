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

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    while (!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
        s1.pop_back();
        s2.pop_back();
    }

    if (s1 == s2) {
        cout << "YES";
        return 0;
    }
    if (s1 == "*") {
        cout << "YES";
        return 0;
    }
    if (s2.empty()) {
        cout << "NO";
        return 0;
    }
    if (s1.empty() || s1.back() != '*') {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < s1.size() - 1; ++i) {
        if (s1[i] != s2[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}