#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> a;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            a.insert(-x);
        }
        multiset<int> s;
        s.insert(-sum);
        while (a.size() && s.size() && *a.begin() >= *s.begin()) {
            if (*a.begin() == *s.begin()) {
                a.erase(a.begin());
                s.erase(s.begin());
                continue;
            }
            int cur = -*s.begin();
            s.erase(s.begin());
            s.insert(-(cur / 2));
            s.insert(-((cur + 1) / 2));
        }
        cout << (a.size() ? "NO\n" : "YES\n");
    }
    return 0;
}