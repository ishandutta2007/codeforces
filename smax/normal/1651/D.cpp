#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 2e5 + 5;

int bit[2 * MAX];
ordered_set<int> qx[2 * MAX], qy[2 * MAX];

int query(int i) {
    int ret = 0;
    for (i=min(i, 2*MAX-1); i>0; i-=i&-i)
        ret += bit[i];
    return ret;
}

void update(int i) {
    for (; i<2*MAX; i+=i&-i)
        bit[i]++;
}

void print(int a, int b) {
    // x + y = a
    // x - y = b
    // x = (a + b) / 2
    // y = (a - b) / 2
    b -= MAX;
    assert((a & 1) == (b & 1));
    cout << (a + b) / 2 << " " << (a - b) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> pts;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        pts.emplace_back(x + y, x - y + MAX);
    }
    
    // cerr << "input read\n";
    // int rep = 0;
    
    vector<int> l(n), r(n, MAX);
    while (true) {
        // cerr << "rep: " << ++rep << "\n";
        vector<array<int, 4>> sweep, rsweep;
        vector<int> m(n);
        bool done = true;
        for (int i=0; i<n; i++) {
            if (l[i] < r[i]) {
                m[i] = (l[i] + r[i]) / 2;
                sweep.push_back({pts[i].first - m[i] - 1, pts[i].second, -1, i});
                sweep.push_back({pts[i].first, pts[i].second, 1, i});
                rsweep.push_back({pts[i].first + m[i], pts[i].second, -1, i});
                rsweep.push_back({pts[i].first, pts[i].second, 1, i});
                done = false;
            } else {
                sweep.push_back({pts[i].first, pts[i].second, 0, i});
                rsweep.push_back({pts[i].first, pts[i].second, 0, i});
            }
        }
        // cerr << "sweep arrays built\n";
        if (done)
            break;
        vector<int> cnt(n);
        // first insert, then query
        sort(sweep.begin(), sweep.end());
        memset(bit, 0, sizeof(bit));
        for (int i=0; i<(int)sweep.size(); ) {
            int j = i;
            while (j < (int) sweep.size() && sweep[i][0] == sweep[j][0]) {
                if (sweep[j][2] != -1)
                    update(sweep[j][1]);
                j++;
            }
            // cerr << i << ", " << j << ": " << sweep[i][0] << ", " << sweep[i][1] << ", " << sweep[i][2] << ", " << sweep[i][3] << "\n";
            for (int k=i; k<j; k++)
                if (sweep[k][2] != 0)
                    cnt[sweep[k][3]] += sweep[k][2] * (query(sweep[k][1] + m[sweep[k][3]]) - query(sweep[k][1] - m[sweep[k][3]] - 1));
            // cerr << "done\n";
            i = j;
        }
        // cerr << "forward sweep done\n";
        // first query, then insert
        sort(rsweep.rbegin(), rsweep.rend());
        memset(bit, 0, sizeof(bit));
        for (int i=0; i<(int)rsweep.size(); ) {
            int j = i;
            while (j < (int) rsweep.size() && rsweep[i][0] == rsweep[j][0]) {
                if (rsweep[j][2] != 0)
                    cnt[rsweep[j][3]] += rsweep[j][2] * (query(rsweep[j][1] + m[rsweep[j][3]]) - query(rsweep[j][1] - m[rsweep[j][3]] - 1));
                j++;
            }
            for (int k=i; k<j; k++)
                if (rsweep[k][2] != -1)
                    update(rsweep[k][1]);
            i = j;
        }
        for (int i=0; i<n; i++)
            if (l[i] < r[i]) {
                // cerr << i << ": " << l[i] << " < " << r[i] << " with " << m[i] << " = " << cnt[i] << "\n";
                if (cnt[i] < 2LL * m[i] * (m[i] + 1) + 1)
                    r[i] = m[i];
                else
                    l[i] = m[i] + 1;
            }
    }
    
    // cerr << "binary search done\n";
    
    for (auto [x, y] : pts) {
        qx[x].insert(y);
        qy[y].insert(x);
    }
    
    for (int i=0; i<n; i++) {
        {
            // check left border
            auto &st = qx[pts[i].first - l[i]];
            auto it = st.lower_bound(pts[i].second - l[i]);
            if (it == st.end() || *it != pts[i].second - l[i]) {
                print(pts[i].first - l[i], pts[i].second - l[i]);
                goto done;
            }
            int base = (int) st.order_of_key(pts[i].second - l[i]);
            int lo = 0, hi = l[i] + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int y = pts[i].second - l[i] + 2 * mid;
                if (st.find(y) == st.end()) {
                    print(pts[i].first - l[i], y);
                    goto done;
                }
                if ((int) st.order_of_key(y) - base < mid)
                    hi = mid;
                else
                    lo = mid + 1;
            }
        }
        {
            // check right border
            auto &st = qx[pts[i].first + l[i]];
            auto it = st.lower_bound(pts[i].second - l[i]);
            if (it == st.end() || *it != pts[i].second - l[i]) {
                print(pts[i].first + l[i], pts[i].second - l[i]);
                goto done;
            }
            int base = (int) st.order_of_key(pts[i].second - l[i]);
            int lo = 0, hi = l[i] + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int y = pts[i].second - l[i] + 2 * mid;
                if (st.find(y) == st.end()) {
                    print(pts[i].first + l[i], y);
                    goto done;
                }
                if ((int) st.order_of_key(y) - base < mid)
                    hi = mid;
                else
                    lo = mid + 1;
            }
        }
        {
            // check bottom border
            auto &st = qy[pts[i].second - l[i]];
            auto it = st.lower_bound(pts[i].first - l[i]);
            if (it == st.end() || *it != pts[i].first - l[i]) {
                print(pts[i].first - l[i], pts[i].second - l[i]);
                goto done;
            }
            int base = (int) st.order_of_key(pts[i].first - l[i]);
            int lo = 0, hi = l[i] + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int x = pts[i].first - l[i] + 2 * mid;
                if (st.find(x) == st.end()) {
                    print(x, pts[i].second - l[i]);
                    goto done;
                }
                if ((int) st.order_of_key(x) - base < mid)
                    hi = mid;
                else
                    lo = mid + 1;
            }
        }
        {
            // check top border
            auto &st = qy[pts[i].second + l[i]];
            auto it = st.lower_bound(pts[i].first - l[i]);
            if (it == st.end() || *it != pts[i].first - l[i]) {
                print(pts[i].first - l[i], pts[i].second + l[i]);
                goto done;
            }
            int base = (int) st.order_of_key(pts[i].first - l[i]);
            int lo = 0, hi = l[i] + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int x = pts[i].first - l[i] + 2 * mid;
                if (st.find(x) == st.end()) {
                    print(x, pts[i].second + l[i]);
                    goto done;
                }
                if ((int) st.order_of_key(x) - base < mid)
                    hi = mid;
                else
                    lo = mid + 1;
            }
        }
        assert(false);
        done:;
    }
    
    return 0;
}