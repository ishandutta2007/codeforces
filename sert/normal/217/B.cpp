#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 503;

string s;
int res;
int r, n, bst = 1e9, ps = -1;
int k;

bool go(int a, int b, int r, bool ou) {
    if ((a == 0 || b == 0) && a + b == 1)
        return !r;
    if (r <= 0 || a <= 0 || b <= 0)
        return false;

    if (a < b) {
        k = b / a;
        res += k - 1;
        if (ou)
            for (int i = 0; i < k; i++)
                s += 'B';
        return go(a, b % a, r - k, ou);
    } else {
        k = a / b;
        res += k - 1;
        if (ou)
            for (int i = 0; i < k; i++)
                s += 'T';
        return go(a % b, b, r - k, ou);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> r >> n;
    if (r == n && r == 1) {
        cout << "0\nT\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        res = 0;
        if (go(i, n, r, false)) {
            if (res < bst) {
                bst = res;
                ps = i;
            }
        }
    }

    if (ps == -1)
        cout << "IMPOSSIBLE";
    else {
        res = 0;
        s.clear();
        go(ps, n, r, true);
        reverse(s.begin(), s.end());
        if (s[0] == 'B')
            for (int i = 0; i < s.length(); i++)
                s[i] = (s[i] == 'B' ? 'T' : 'B');

        if (r > 1 && s[1] == 'T') {
            res--;
            for (int i = 1; i < s.length(); i++)
                s[i] = (s[i] == 'B' ? 'T' : 'B');
        }

        if (r > 1) {
            if (s[s.length() - 1] == s[s.length() - 2]) {
                res--;
                s.back() = (s.back() == 'T' ? 'B' : 'T');
            }
        }
        cout << res << "\n" << s << "\n";
    }

    return 0;
}