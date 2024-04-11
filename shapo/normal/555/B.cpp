#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;
typedef vector< ll > vll;
typedef pair< ll, ll > pll;
typedef vector< pll > vpll;

int n, m;
vll l, r;
vector< pair< ll, int > >  len;
vector< int > ans;

set< pair< ll, int > > ids;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    l.resize(n), r.resize(n);
    ans.resize(n - 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    len.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> len[i].first;
        len[i].second = i;
    }
    sort(len.begin(), len.end());
    vector< pair< ll, pair< ll, int > > > segs;
    for (int i = 1; i < n; ++i) {
        ll from = l[i] - r[i - 1], to = r[i] - l[i - 1];
        segs.push_back({from, {to, i}});
    }
    sort(segs.begin(), segs.end());
    ids.clear();
    int l_b = 0, r_b = 0;
    while (l_b < m) {
        while (r_b < n - 1 && segs[r_b].first <= len[l_b].first) {
            ids.insert(segs[r_b].second);
            ++r_b;
        }
        if (!ids.empty()) {
            auto val = *(ids.begin());
            if (val.first >= len[l_b].first) {
                ans[val.second - 1] = len[l_b].second;
            }
            ids.erase(val);
        }
        ++l_b;
    }
    bool ok = true;
    for (int i = 0; ok && i < n - 1; ++i) {
        ok = (ans[i] != -1);
    }
    if (ok) {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; ++i) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << "No\n";
    }
    return 0;
}