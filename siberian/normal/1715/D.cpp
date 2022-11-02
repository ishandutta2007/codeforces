#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Event{
    int i, j, x;
    bool operator<(const Event& other) const {
        return i < other.i;
    }
};

const int N = 1e5 + 10;
const int Q = 2e5 + 10;
const int LOG = 30;
int n, q;
int ans[N];
// int OR[N];
int AND[N];
Event events[Q];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        AND[i] = (1 << LOG) - 1;
        ans[i] = 0;
    }
    for (int i = 0; i < q; ++i) {
        cin >> events[i].i >> events[i].j >> events[i].x;
        if (events[i].i > events[i].j) {
            swap(events[i].i, events[i].j);
        }
        --events[i].i;
        --events[i].j; 
        AND[events[i].i] &= events[i].x; 
        AND[events[i].j] &= events[i].x; 
    }
    sort(events, events + q);
    for (int l = 0; l < q; ++l) {
        int r = l;
        while (r < q && events[r].i == events[l].i) {
            for (int bit = 0; bit < LOG; ++bit) {
                if (!((events[r].x >> bit) & 1)) {
                    continue;
                }
                if (events[r].j != events[r].i) {
                    if ((AND[events[r].j] >> bit) & 1) {
                        // ans[events[r].j] |= (1 << bit);
                    } else {
                        ans[events[r].i] |= (1 << bit);
                    }
                } else {
                    ans[events[r].i] |= (1 << bit);
                }
            }
            ++r;
        }
        r = l;
        while (r < q && events[r].i == events[l].i) {
            for (int bit = 0; bit < LOG; ++bit) {
                if (!((events[r].x >> bit) & 1)) {
                    continue;
                }
                if ((ans[events[r].i] >> bit) & 1) {
                    continue;
                }
                if ((AND[events[r].j] >> bit) & 1) {
                    ans[events[r].j] |= (1 << bit);
                } else {
                    // ans[events[r].i] |= (1 << bit);
                }
            }
            ++r;
        }
        l = r - 1;
    }
    // for (int i = 0; i < q; ++i) {
    // }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}