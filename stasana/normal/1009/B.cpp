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

    string s = input<string>();
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '2') {
            break;
        }
        if (s[i] == '0') {
            cout << s[i];
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            cout << s[i];
        }
    }

    bool f = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '2') {
            f = true;
        }
        if (s[i] != '1' && f) {
            cout << s[i];
        }
    }
    return 0;
}