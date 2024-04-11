#include <bits/stdc++.h>
using namespace std;

int t[1005];

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int j, k;
        cin >> j >> k;
        t[j] = max(t[j], k);
    }
    int cur = 0;
    for(int i = s; i > 0; i--) {
        cur = max(cur, t[i]);
        cur++;
    }
    cout << cur << endl;
}