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

const ll N = 1e6 + 34;

ll go(ll l1, ll r1, ll l2, ll r2) {
    return max(0ll, min(r1, r2) - max(l1, l2) + 1);
}

set <int> s;

int main() {
    init();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    if (s.size() > 3) {
        cout << "NO\n";
        return 0;
    }

    if (s.size() < 3) {
        cout << "YES\n";
        return 0;
    }

    int a = *(s.begin()); s.erase(s.begin());
    int b = *(s.begin()); s.erase(s.begin());
    int c = *(s.begin()); s.erase(s.begin());

    if (a + c == 2 * b)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}