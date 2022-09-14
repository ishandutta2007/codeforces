#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x = 0, t;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        m[t]++;
        x = max(x, m[t]);
    }
    cout << x;
}