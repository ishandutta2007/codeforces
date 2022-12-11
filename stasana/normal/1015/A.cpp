#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
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

void solveFirst(int n, vector<vector<int>>& a) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            ++count;
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            cout << i + 1 << " ";
        }
    }
}

void solveSecond(int n, vector<vector<int>>& a) {
    vector<int> result;
    for (int id = 0; id < n; ++id) {
        vector<int> good;
        vector<int> bad;
        for (int i = 0; i < n; ++i) {
            if (a[i][i] < a[i][id]) {
                bad.emplace_back(i);
            }
            if (a[i][i] >= a[i][id]) {
                good.emplace_back(i);
            }
        }

        int ptr = 0;
        while (ptr != bad.size()) {
            bool f = true;
        }

        bool f = true;
        while (f && !good.empty()) {
            f = false;
            for (auto i : bad) {
                if (a[good.back()][good.back()] > a[good.back()][i]) {
                    f = true;
                    good.pop_back();
                    break;
                }
            }
        }

        if (!good.empty()) {
            result.emplace_back(id);
        }
    }
    cout << result.size() << endl;
    for (auto i : result) {
        cout << i + 1 << " ";
    }
}

int main() {
    start();

    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1);
    for (int i = 0; i < n; ++i) {
        int left  = input<int>() - 1;
        int right = input<int>();
        ++a[left];
        --a[right];
    }
    int count = 0;
    for (int i = 0; i < m; ++i) {
        if (i != 0) {
            a[i] = a[i] + a[i - 1];
        }
        
        if (a[i] == 0) {
            ++count;
        }
    }
    cout << count << endl;
    for (int i = 0; i < m; ++i) {
        if (a[i] == 0) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}