#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
int fnd(string a, string b) {
    int cnt = 0;
    int dif = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '1')
            cnt++;
        if (b[i] == '1')
            cnt--;
        if (a[i] != b[i])
            dif++;
    }
    if (cnt == 0)
        return dif;
    return -1;
}
void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int res = fnd(a, b);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' and b[i] == '1') {
            string c = a;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                c[j] = '1' + '0' - c[j];
            }
            //cout << a << ' ' << c << endl;
            int r2 = fnd(c, b);
            if (r2 != -1) {
                r2++;
                if (res == -1)
                    res = r2;
                else
                    res = min(res, r2);
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            string c = a;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                c[j] = '1' + '0' - c[j];
            }
            int r2 = fnd(c, b);
            if (r2 != -1) {
                r2++;
                if (res == -1)
                    res = r2;
                else
                    res = min(res, r2);
            }
            break;
        }
    }
    cout << res << '\n';
}
signed main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}