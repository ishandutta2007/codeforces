#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

pair <int, int> a[N];
set<int> b;
int n, m, t, k;
int len;
string s;
map <int, int> bac;
int d[N], ans, v;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        bac[a[i].first] = i;
    }
    b.insert(1e8);
    for (int i = 0; i < n; i++) {
        m = *b.upper_bound(-a[i].first + a[i].second);
        if (m > 0) {
            d[i] = 1;
            ans = max(ans, 1);
        } else {
            v = bac[-m];
            d[i] = d[v] + 1;
            ans = max(ans, d[i]);
        }
        b.insert(-a[i].first);
    }

    cout << n - ans;

    return 0;
}