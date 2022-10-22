#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
const int MOD = 1e9 + 7;

int power(int n, int k) {
    if (k == 0) return 1;
    if (k == 1) return n;
    int x = power(n, k / 2);
    int ans = x * x % MOD;
    if (k % 2 == 0) {
        return ans;
    } else {
        return (ans * n) % MOD;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int st, fin;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            st = i;
        }
        if (s[i] == 'T') {
            fin = i;
        }
    }
    int i = st;
    while (true) {
        if (st < fin) {
            if (i > fin || s[i] == '#') {
                cout << "NO";
                return 0;
            }
            if (i == fin) {
                cout << "YES";
                return 0;
            }
            i += m;
            continue;
        } else {
            if (i < fin || s[i] == '#') {
                cout << "NO";
                return 0;
            }
            if (i == fin) {
                cout << "YES";
                return 0;
            }
            i -= m;
        }
    }
}