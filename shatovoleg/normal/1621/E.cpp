#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

bool cmp(int tutor, pll group) {
    return tutor * group.second >= group.first;
}

void calc_partial_sum_inplace(vector<int>& v) {
    partial_sum(all(v), v.begin());
    v.insert(v.begin(), 0);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> tutors(n);
    for (auto& x : tutors) {
        cin >> x;
    }
    sort(all(tutors));
    tutors.erase(tutors.begin(), tutors.end() - m);
    vector<vector<int>> groups(m);
    vector<pll> avg(m, {0, 0});
    int total_students = 0;
    for (int i = 0; i < m; ++i) {
        auto& group = groups[i];
        int n;
        cin >> n;
        total_students += n;
        avg[i].second = n;
        group.resize(n);
        for (auto& x : group) {
            cin >> x;
            avg[i].first += x;
        }
    }

    auto pll_cmp = [](pll a, pll b) {
        return a.first * b.second < b.first * a.second;
    };

    vector<int> avg_pos(m, -1);
    {
        vector<pll> sorted_avg(all(avg));
        sort(all(sorted_avg), pll_cmp);
        for (int i = 0; i < m; ++i) {
            avg_pos[i] = (int)(lower_bound(all(sorted_avg), avg[i], pll_cmp) - sorted_avg.begin());;
        }
        avg.swap(sorted_avg);
    }

    vector<int> good(m, 0), good_left(m, 0);
    int bad_group = -1;

    for (int i = 0; i < m; ++i) {
        if (cmp(tutors[i], avg[i])) {
            good[i] = 1;
        }
        if (i > 0 && cmp(tutors[i - 1], avg[i])) {
            good_left[i] = 1;
        }
        if (!cmp(tutors[min(m - 1, i + 1)], avg[i])) {
            if (bad_group == -1) {
                bad_group = i;
            } else {
                cout << string(total_students, '0') << '\n';
                return;
            }
        }
    }
    calc_partial_sum_inplace(good);
    calc_partial_sum_inplace(good_left);

    for (int i = 0; i < m; ++i) {
        for (const auto x : groups[i]) {
            int old_pos = avg_pos[i];
            if (bad_group != -1 && bad_group != old_pos) {
                cout << 0;
                continue;
            }
            pll new_avg = avg[old_pos];
            new_avg.first -= x;
            --new_avg.second;
            int new_pos = (int)(lower_bound(all(avg), new_avg, pll_cmp) - avg.begin());
            if (new_pos > old_pos) {
                --new_pos;
            }
            if (!cmp(tutors[new_pos], new_avg)) {
                cout << 0;
                continue;
            }
            int total_good = good.back();
            if (!cmp(tutors[old_pos], avg[old_pos])) {
                ++total_good;
            }
            bool flag = true;
            if (new_pos >= old_pos) {
                int l = old_pos + 1, r = new_pos + 1;
                if (good_left[r] - good_left[l] != r - l || total_good != m) {
                    flag = false;
                }
            }
            if (new_pos < old_pos) {
                int l = new_pos, r = old_pos;
                if (total_good - (good[r] - good[l]) + (r - l) != m) {
                    flag = false;
                }
            }
            cout << flag;
        }
    }
    cout << '\n';
}