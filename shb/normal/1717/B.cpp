#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        --r; --c;
        r %= k; c %= k;
        vector<int> idx(k);
        for (int i = 0; i < k; i++) idx[i] = i;
        swap(idx[r], idx[c]); // idx[r] = c
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = i % k;
                int y = j % k;
                if (y == idx[x]) {
                    cout << 'X';
                } else {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
}