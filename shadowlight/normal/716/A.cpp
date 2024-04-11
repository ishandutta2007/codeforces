#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, c;
    cin >> n >> c;
    int prev = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x - prev > c) {
            cnt = 1;
        } else {
            cnt++;
        }
        prev = x;
    }
    cout << cnt;
}
/*
9 10
99999.445
*/