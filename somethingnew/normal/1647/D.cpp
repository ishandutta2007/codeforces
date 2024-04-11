#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "climits"
#include "queue"
#include "array"
#include "numeric"
#include "random"
using namespace std;
#define all(x) x.begin(), x.end()
bool prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int onediv(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            if (x == 1)
                return i;
            return 0;
        }
    }
    return x;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    while (n % m == 0) {n /= m;cnt++;}
    if (cnt == 1) {
        cout << "NO\n";
    } else if (!prime(n)) {
        cout << "YES\n";
    } else {
        if (!onediv(m)) {
            if (cnt >= 3)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            int t = onediv(m);
            int cntm = 0;
            while (m % t == 0) {
                m /= t;
                cntm++;
            }
            int cntn = 0;
            if (n == t)
                cntn = 1;
            if ((cnt * cntm + cntn + cnt - 2) / (cnt - 1) < cntm * 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}