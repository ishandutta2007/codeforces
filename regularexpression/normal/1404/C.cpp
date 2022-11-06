#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 239;

int n, q, a[N];
int x[N], y[N];
vector <int> here[N];
int t[N], ans[N], cur;

void add(int pos, int delta) {
    for (++pos; pos < N; pos += pos & -pos)
        t[pos] += delta;
}

int query(int pos) {
    int res = cur;
    for (; pos > 0; pos -= pos & -pos)
        res += t[pos];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        a[i] = i - a[i];
        if (a[i] < 0)
            a[i] = n;
    }
    for (int i = 0; i < q; ++i) {
        cin >> x[i] >> y[i];
        y[i] = n - y[i];
        here[y[i]].push_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        for (auto elem : here[i]) ans[elem] = query(x[elem] + 1);
        if (i != n) {
            int l = -1, r = i + 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (query(mid + 1) >= a[i])
                    l = mid;
                else
                    r = mid;
            }
            ++cur;
            add(l + 1, -1);
        }
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
    return 0;
}