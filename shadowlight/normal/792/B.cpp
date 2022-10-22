#include <bits/stdc++.h>

using namespace std;

const int INF = 2 * 1e9 + 9;

int main() {
    int n, m;
    cin >> n >> m;
    int now = 0;
    vector <int> used(n, 0);
    for (int j = 0; j < m; j++) {
        int a;
        cin >> a;
        a %= n - j;
        int sum = 0;
        int now1 = (now + 1) % n;
        while (sum < a) {
            if (!used[now1]) {
                sum++;
            }
            now1++;
            now1 %= n;
        }
        used[(now1 - 1 + n) % n] = 1;
        cout << (now1 - 1 + n) % n + 1 << " ";
        now = now1;
        while (used[now]) {
            now++;
            now %= n;
        }
    }
}