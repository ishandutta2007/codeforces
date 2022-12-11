#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;


int main() {
    init();
    int n, k, g, t;
    string s;
    bool u[112];
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') u[i] = true; else u[i] = false;
        if (s[i] == 'G') g = i;
        if (s[i] == 'T') t = i;
    }
    if (g > t) swap(g, t);
    if (g % k != t % k) {
        cout << "NO";
        return 0;
    }
    for (int i = g; i < t; i += k)
    if (u[i]) {cout << "NO"; return 0;}
    cout << "YES";
    return 0;
}