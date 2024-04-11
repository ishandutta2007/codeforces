#include <bits/stdc++.h>
 
using namespace std;

struct fTree {
    int sz;
    long long * t;

    fTree(int n) {
        sz = n;
        t = new long long[sz];
        memset(t, 0, sz * sizeof(long long));
    }

    long long get(int r) {
        long long res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res += t[r];
        }
        return res;
    }

    void add(int r, long long add) {
        for (; r < sz; r |= r + 1) {
            t[r] += add;
        }
    }
};

int main() {
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //freopen("2strings.in", "r", stdin);
    //freopen("2strings.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int a[n];

    int b[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);

    fTree one(n), two(n);

    long long ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        int v = lower_bound(b, b + n, a[i]) - b;
        ans += two.get(v - 1);
        long long addTwo = one.get(v - 1);
        long long addOne = 1;

        one.add(v, addOne);
        two.add(v, addTwo);
    }

    cout << ans << endl;

    return 0;
}