#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool check(vector<bool> a) {
    for (int i = 0; i < (int)a.size(); ++i) {
        if (!a[i]) {
            return false;
        }
    }
    return true;
}

int solve(int n, int k, vector<int> a) {
    vector<bool> used(n);
    int i = 0;
    while (true) {
        for (int j = 0; j < k; ++j) {
            if (n > a[j] + i) {
                used[a[j] + i] = true;
            }
            if (a[j] - i >= 0) {
                used[a[j] - i] = true;
            }
        }
        if (check(used)) {
            return i;
        }
        ++i;
    }
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            --a[i];
        }
        cout << solve(n, k, a) + 1 << endl;
    }
}