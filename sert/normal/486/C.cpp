#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
const ll md = 1e9 + 7;

ll a, b, q, ans, n, p;
string s;
char c1, c2;
ll f = -1, l;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> p >> s;
    p--;
    if (p >= n / 2)
        p = n - p - 1;

    for (int i = 0; i < n / 2; i++) {
        c1 = s[i];
        c2 = s[n - i - 1];
        ans += min((c1 - c2 + 26) % 26, (c2 - c1 + 26) % 26);
        if (c1 != c2) {
            if (f == -1)
                f = i;
            l = i;
        }
    }

    if (f == -1) {
        cout << 0;
        return 0;
    }

    ans += l - f;
    ans += min(abs(p - l), abs(p - f));

    cout << ans;

    //return 0;
}