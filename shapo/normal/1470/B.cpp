#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef ve<int> vi;
typedef long long ll;

vi
prepare(int max_v)
{
    int lbl = 0;
    vi labels(max_v + 1, -1);
    for (int i = 1; i <= max_v; ++i) {
        if (labels[i] == -1) {
            for (int j = 1; 1ll * j * j * i <= max_v; ++j) {
                labels[j * j * i] = lbl;
            }
            ++lbl;
        }
    }
    return labels;
}

void
solve(const vi& labels)
{
    int n, q;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> counts_0, counts_1;
    for (int i = 0; i < n; ++i) {
        counts_0[labels[a[i]]]++;
    }
    for (auto [n, cnt] : counts_0) {
        if (cnt & 1) {
            counts_1[n] = cnt;
        } else {
            counts_1[labels[1]] += cnt;
        }
    }
    int max_0 = 0, max_1 = 1;
    for (auto [_, cnt] : counts_0) {
        max_0 = max(max_0, cnt);
    }
    for (auto [_, cnt] : counts_1) {
        max_1 = max(max_1, cnt);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll w;
        cin >> w;
        cout << (w == 0 ? max_0 : max_1) << '\n';
    }
}

int
main()
{
    cin.sync_with_stdio(false);
    auto labels = prepare(1111111);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve(labels);
    }
    return 0;
}