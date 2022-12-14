#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
            ai -= 1;
        }
        if (n == 1) {
            cout << "YES\n";
            continue;
        }
        if (n == 2) {
            if (a[0] <= a[1]) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        vector<int> p(n, -1);
        int s = 0;
        for (int i = 0; i < n; i += 1) {
            if (p[a[i]] != -1) {
                s = 1;
                break;
            }
            p[a[i]] = i;
        }
        if (s) {
            cout << "YES\n";
            continue;
        }
        int inv = 0;
        for (int i = 0; i < n; i += 1) if (a[i] != i) {
            inv ^= 1;
            int j = p[i];
            swap(p[a[i]], p[a[j]]);
            swap(a[i], a[j]);
        }
        if (inv) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}