#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n == 0) {
            if (n == 1) {
                cout << "0" << '\n';
            } else {
                vector<tuple<int, int, int> > ans;

                auto f = [&](int i, int j, int x) {
                    ans.emplace_back(i, j, x);
                    assert(a[i] >= x * i);
                    a[i] -= x * i;
                    a[j] += x * i;
                };

                for (int i = 2; i <= n; ++i) {
                    f(1, i, (i - a[i] % i) % i);
                    f(i, 1, a[i] / i);
                }

                for (int i = 2; i <= n; ++i)
                    f(1, i, sum / n);

                cout << ans.size() << '\n';
                for (const auto &[i, j, x] : ans)
                    cout << i << " " << j << " " << x << '\n';

                for (int i = 1; i <= n; ++i)
                    assert(a[i] == sum / n);
            }
        } else {
            cout << "-1" << '\n';
        }
    }
    return 0;
}