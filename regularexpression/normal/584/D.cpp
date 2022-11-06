#include<bits/stdc++.h>
using namespace std;

inline bool check(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

vector<int> get(int n) {
    if (check(n)) return {n};
    for (int i = 1; i <= n; i++) {
        if (check(i) && check(n - i)) return {i, n - i};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (check(n)) {
        cout << 1 << endl << n;
        return 0;
    }
    if (check(n - 2)) {
        cout << 2 << endl << 2 << " " << n - 2;
        return 0;
    }
    for (int i = 4; i <= min(1000, n); i += 2) {
        if (check(n - i)) {
            cout << 3 << endl << n - i;
            auto ans = get(i);
            for (auto elem : ans) cout << " " << elem;
            return 0;
        }
    }
    return 0;
}