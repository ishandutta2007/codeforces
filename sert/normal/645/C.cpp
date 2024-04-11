#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 2e6 + 34;
string s;
int n, k;

int mov(int c) {
    if (c >= n) return n;
    c++;
    while (s[c] == '1') {
        c++;
        if (c >= n)
            return n;
    }
    return c;
}
int c1, c3, ans = 1e9;
int res(int c) {
    return max(abs(c - c3), abs(c - c1));
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k >> s;
    k++;

    c1 = mov(-1);
    c3 = -1;
    for (int i = 0; i < k; i++) c3 = mov(c3);
    int c2 = mov(-1);

    while (c3 < n) {
        while (res(c2) >= res(mov(c2)))
            c2 = mov(c2);
        ans = min(ans, res(c2));
        c1 = mov(c1);
        c3 = mov(c3);
    }

    cout << ans;

    return 0;
}