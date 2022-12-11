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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 0, cnt = 0, cntN = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i - 1] == a[i]) {
            ++cntN;
        }
        else {
            cnt += cntN;
            cntN = 1;
        }
        if (cnt > 0) {
            ++res;
            --cnt;
        }
    }
    cout << res;
    return 0;
}