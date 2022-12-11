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
bool u[N];

int main() {
    init();
    int n;
    string s;
    int d = 0, p = 0;
    int kd = 0, kp = 0;
    cin >> n >> s;
    int zd, zp;

    for (char ch: s) {
        if (ch == 'D') kd++;
        else kp++;
    }

    if (kd == 0) cout << "R";
    if (kp == 0) cout << "D";

    while (kd > 0 && kp > 0) {
        zd = zp = 0;
        p = d = 0;
        for (int i = 0; i < n; i++) {
            if (u[i]) continue;
            if (s[i] == 'D') {
                if (zp == 0 && p < i) p = i;
                while (s[p] == 'D' || u[p]) {
                    p = (p + 1) % n;
                    if (p == 0) zp = 1;
                }
                u[p] = true;
                kp--;
                if (kp == 0) {
                    cout << "D";
                    return 0;
                }
            } else {
                if (zd == 0 && d < i) d = i;
                while (s[d] == 'R' || u[d]) {
                    d = (d + 1) % n;
                    if (d == 0) zd = 1;
                }

                u[d] = true;
                kd--;
                if (kd == 0) {
                    cout << "R";
                    return 0;
                }
            }
        }
    }

    return 0;
}