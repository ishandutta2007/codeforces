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
    
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (check(s[i]) || s[i] == 'n') {
            continue;
        }
        else {
            if (i == s.length() - 1 || !check(s[i + 1])) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}