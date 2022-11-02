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

#define int ll

struct Frac{
    ll x, y;
    Frac() {}
    Frac(ll _x, ll _y) : x(_x), y(_y) {
        ll g = __gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        if (y < 0) {
            x = -x;
            y = -y;
        }
    }
    bool operator<(const Frac& other) const {
        return x * other.y < y * other.x;
    }
};

struct Person{
    int val, id;
};

struct Group{
    ll sum;
    int cnt;
    vector<Person> values;
    Group() : sum(0), cnt(0), values() {}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(all(a));
    reverse(all(a));
    a.resize(min(n, m));
    reverse(all(a));
    // cerr << "a = " << endl;
    // for (auto i : a) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    n = m;
    sort(all(a));
    vector<Group> has(m);
    int id = 0;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        has[i].cnt = k;
        for (int j = 0; j < k; ++j) {
            int val;
            cin >> val;
            has[i].sum += val;
            has[i].values.push_back({val, id++});
        }
    }
    sort(all(has), [&] (const Group& a, const Group& b) {
        return Frac(a.sum, a.cnt) < Frac(b.sum, b.cnt);
    });
    auto cmp = [&] (int t, int g) -> bool {
        return !(Frac(a[t], 1) < Frac(has[g].sum, has[g].cnt));
    };
    int maxPref = 0;
    while (maxPref < n && cmp(maxPref, maxPref)) ++maxPref;
    int maxSuff = 0;
    while (maxSuff < n && cmp(n - maxSuff - 1, n - maxSuff - 1)) ++maxSuff;
    // cerr << "maxPref = " << maxPref << " maxSuff = " << maxSuff << endl;
    vector<bool> okNext(n, false);
    for (int i = 0; i + 1 < n; ++i) {
        okNext[i] = cmp(i, i + 1);
    }
    vector<int> suffNext(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffNext[i] = okNext[i];
        if (i + 1 < n && okNext[i]) suffNext[i] += suffNext[i + 1];
    }
    vector<bool> okPrev(n, false);
    for (int i = 1; i < n; ++i) {
        okPrev[i] = cmp(i, i - 1);
    }
    vector<int> prefPrev(n, 0);
    for (int i = 0; i < n; ++i) {
        prefPrev[i] = okPrev[i];
        if (i - 1 >= 0 && okPrev[i]) prefPrev[i] += prefPrev[i - 1];
    }
    vector<bool> ans(id, false);

    vector<Frac> hasFrac(n);
    for (int i = 0; i < n; ++i) {
        hasFrac[i] = Frac(has[i].sum, has[i].cnt);
    }

    // cerr << "suffNext = " << endl;
    // for (auto i : suffNext) cerr << i << " ";
    // cerr << endl;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < has[i].cnt; ++j) {
            Frac cur(has[i].sum - has[i].values[j].val, has[i].cnt - 1);
            
            int pos = lower_bound(all(hasFrac), cur) - hasFrac.begin();
            // if(i != 0 || j != 0) continue;
            // cerr << "i = " << i << " j = " << j << " pos = " << pos << endl;
            // cerr << "cur = " << cur.x << " " << cur.y << endl;

            if (cur < hasFrac[i]) {
                if (maxPref < pos) continue;
                // cerr << "puhh" << endl;
                if (prefPrev[i] < i - pos) continue;
                // cerr << "puhh" << endl;
                if (maxSuff < n - i - 1) continue;
                // cerr << "puhh" << endl;
                if (Frac(a[pos], 1) < cur) continue;
                ans[has[i].values[j].id] = true;
            } else if (hasFrac[i] < cur) {
                --pos;
                // cerr << "puhh2"<< endl;
                if (maxPref < i) continue;
                // cerr << "puhh2"<< endl;
                if (maxSuff < n - pos - 1) continue;
                // cerr << "puhh2"<< endl;
                if (suffNext[i] < pos - i) continue;
                // cerr << "puhh"<< endl;
                if (Frac(a[pos], 1) < cur) continue;
                ans[has[i].values[j].id] = true;
            } else {
                if (maxPref == n) {
                    ans[has[i].values[j].id] = true;
                }
            }
        }
    }

    for (auto i : ans) {
        cout << (i ? 1 : 0);
    }
    cout << '\n';
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