#pragma GCC optimize("Ofast")

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

const int N = 1e5 + 10;
int a[N];
int cur_p[N];
int cnt[N];
vector<int> events[N];

int getNext(int x, int p) {
    return max(x / (x / p), p) + 1;
    // while (true) {
    //     if (x / p == 0) {
    //         break;
    //     }
    //     if (x / (p + 1) != x / p) {
    //         break;
    //     }
    //     ++p;
    // }
    // return p + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    fill(cur_p, cur_p + n, 1);
    fill(cnt, cnt + N, 0);
    fill(events, events + N, vector<int>());

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]] = 1;
        events[a[i]].push_back(i);
    }

    int L = 0;
    int R = N - 1;
    while (!cnt[L]) {
        ++L;
    }
    while (!cnt[R]) {
        --R;
    }

    // cerr << "L = " << L << " R = " << R << endl;

    int ans = R - L;

    while (R > 0) {
        for (auto i : events[R]) {
            int p = cur_p[i];
            int next = getNext(a[i], cur_p[i]);
            if (next >= k + 1) {
                cout << ans << '\n';
                return;
            }
            --cnt[a[i] / p];
            int x = a[i] / next;
            ++cnt[x];
            events[x].push_back(i);
            cur_p[i] = next;
            chkmin(L, x);
        }

        vector<int>().swap(events[R]);
        --R;
        chkmin(ans, R - L);
    }

    chkmin(ans, R - L);

    cout << ans << '\n';

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
    return 0;
}