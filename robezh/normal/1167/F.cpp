#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = (int)5e5 + 500, mod = (int)1e9 + 7;

int n;
P p[N];

struct BIT {
    ll bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }

} bit[2];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first; p[i].second = i;
    }
    sort(p, p + n);
    ll res = 0;
    for(int t = 0; t < n; t++) {
        int i = p[t].second;
        bit[0].add(i, i + 1);
        bit[1].add(i, n - i);
        ll tot_rank = bit[0].get(0, i - 1) * (n - i) +
                bit[1].get(i + 1, n - 1) * (i + 1);
        tot_rank += 1LL * (n - i) * (i + 1);
        tot_rank %= mod;
        res += tot_rank * p[t].first % mod;
    }
    res = (res % mod + mod) % mod;
    cout << res << endl;
}