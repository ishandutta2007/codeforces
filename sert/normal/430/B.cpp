#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

int a[N], n, k, x;
vector <int> l, r;
int ans, res, cur, q;

int go(int p) {
    l.clear();
    r.clear();
    res = 0;
    l.push_back(-1);
    r.push_back(-2);
    for (int i = 0; i < p; i++) l.push_back(a[i]);
    for (int i = n - 1; i >= p + 2; i--) r.push_back(a[i]);

    while (l.back() == r.back()) {
        cur = 0;
        q = l.back();
        while (l.back() == q) {cur++; l.pop_back();}
        while (r.back() == q) {cur++; r.pop_back();}
        if (cur < 3) return res;
        res += cur;
    }
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        if (a[i - 1] == x && a[i] == x) {
            ans = max(ans, 2 + go(i - 1));
        }

    cout << ans;

    return 0;
}