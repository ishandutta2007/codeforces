#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef int_fast64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

template<class T>
T input() {
    T value;
    cin >> value;
    return value;
}



int main() {
    start();

    int n = input<int>();
    string s = input<string>();
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + s[i - 1] - '0';
    }
    if (p.back() == 0) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i < p.back(); ++i) {
        if (p.back() % i != 0) {
            continue;
        }
        int left = 0, right = 0;
        int f = 1;
        for (int j = 0; j < p.back() / i; ++j) {
            while (right < n && p[right] - p[left] < i) {
                ++right;
            }
            if (p[right] - p[left] != i) {
                f = 0;
                break;
            }
            else {
                left = right;
            }
        }
        if (f) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}