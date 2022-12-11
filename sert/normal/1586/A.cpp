#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    int mn = -1;
    if (is_prime(sum)) {
        for (int i = 0; i < n; i++) {
            if ((mn == -1 || a[i] < a[mn]) && !is_prime(sum - a[i])) {
                mn = i;
            }
        }
    }
    cout << (mn == -1 ? n : n - 1) << "\n";
    for (int i = 0; i < n; i++) {
        if (i != mn) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    int t;
    if (D) {
        freopen("../a.in", "r", stdin);
    }
    cin >> t;
    while (t--) {
        solve();
    }
}