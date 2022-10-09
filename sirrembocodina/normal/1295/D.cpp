#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

bool notp[100100];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n = 100010;
    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (notp[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            notp[j] = true;
        }
        p.push_back(i);
    }
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int a, m;
        cin >> a >> m;
        m /= __gcd(a, m);
        int phi = 1;
        for (int x: p) {
            if (x * x > m) {
                break;
            }
            if (m % x) {
                continue;
            }
            int pow = 0;
            while (m % x == 0) {
                m /= x;
                pow++;
            }
            for (int i = 0; i < pow - 1; i++) {
                phi *= x;
            }
            phi *= x - 1;
        }
        if (m > 1) {
            phi *= m - 1;
        }
        cout << phi << endl;
    }
}