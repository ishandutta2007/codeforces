#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int q = 0;
    for (auto c : s) q += (c == '?');
    if (x > y) {
        swap(x, y);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else if (s[i] == '1') {
                s[i] = '0';
            }
        }
    }

    int e = 0, z = 0;
    int ans = 0;
    for (auto c : s) {
        if (c == '0') {
            z++;
            ans += e * y;
        } else if (c == '1') {
            e++;
            ans += z * x;
        }
    }
    int ae = e, az = z;
    int E = 0, Z = 0;
    int ue = 0;
    for (auto c : s) {
        if (c == '?') {
            Z += ue;
            E += (az - ue);
        } else if (c == '0') {
            ue++;
        }
    }
    e = 0;
    z = 0;
    int a = 0, b = 0;
    for (auto c : s) b += (c == '?');
    int a2 = x * a * b + y * E + x * Z;

    for (auto c : s) {
        if (c == '0') {
            z++;
        } else if (c == '1') {
            e++;
        } else {
            E += (e+z-az);
            Z += (ae-e-z);
            a++;
            b--;
            a2 = min(a2, x * a * b + y * E + x * Z);
        }
    }
    cout << ans + a2 << '\n';
}