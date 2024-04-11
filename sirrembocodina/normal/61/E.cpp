#include "bits/stdc++.h"

#define forn(i, n) for (int i = 0; i < n; i++)
#define int long long

using namespace std;

const int TREE_SZ = 1 << 21;

vector<int> sum(TREE_SZ);

void add_elem(int v, int l, int r, int x) {
    sum[v] += 1;
    if (l == r - 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        add_elem(2 * v + 1, l, m, x);
    } else {
        add_elem(2 * v + 2, m, r, x);
    }
}

int get_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return 0;
    }
    if (L <= l && r <= R) {
        return sum[v];
    }
    int m = (l + r) / 2;
    return get_sum(2 * v + 1, l, m, L, R) +
           get_sum(2 * v + 2, m, r, L, R);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> M;
    forn (i, n) {
        M[b[i]] = i;
    }
    forn (i, n) {
        a[i] = M[a[i]];
    }
    vector<int> l_more(n), r_less(n);
    forn (i, n) {
        l_more[i] = get_sum(0, 0, n, a[i] + 1, n);
        add_elem(0, 0, n, a[i]);
    }
    sum.assign(TREE_SZ, 0);
    for (int i = n - 1; i >= 0; i--) {
        r_less[i] = get_sum(0, 0, n, 0, a[i]);
        add_elem(0, 0, n, a[i]);
    }
    int ans = 0;
    forn (i, n) {
        ans += l_more[i] * r_less[i];
    }
    cout << ans << endl;
}