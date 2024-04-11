#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Item{
    int pos;
    char type;
    int ind;
};



void solve() {
    int n, m;
    cin >> n >> m;
    vector<Item> have(n);
    for (int i = 0; i < n; ++i) {
        cin >> have[i].pos;
    }
    for (int i = 0; i < n; ++i) {
        cin >> have[i].type;
    }
    for (int i = 0; i < n; ++i) {
        have[i].ind = i;
    }
    sort(all(have), [&] (const Item& a, const Item& b) {
        return a.pos < b.pos;
    });
    // cerr << "have = " << endl;
    // for (auto i : have) {
    //     cerr << "pos = " << i.pos << " type = " << i.type << " ind = " << i.ind << endl;
    // }
    vector<vector<int>> st(2);
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int type = have[i].pos % 2;
        if (st[type].empty()) {
            st[type].push_back(i);
        } else {
            if (have[i].type == 'R') {
                st[type].push_back(i);
            } else {
                if (have[st[type].back()].type == 'R') {
                    // cerr << "i = " << i << " st.back() = " << st[type].back() << endl;
                    int len = have[i].pos - have[st[type].back()].pos;
                    assert(len % 2 == 0);
                    ans[have[i].ind] = len / 2;
                    ans[have[st[type].back()].ind] = len / 2;
                    st[type].pop_back();
                } else {
                    // cerr << "i = " << i << " st.back() = " << st[type].back() << endl;
                    assert(st[type].size() == 1);
                    int len = have[st[type].back()].pos + have[i].pos;
                    assert(len % 2 == 0);
                    ans[have[i].ind] = len / 2;
                    ans[have[st[type].back()].ind] = len / 2;
                    st[type].pop_back();    
                }
            }
        }
    } 
    for (int it = 0; it < 2; ++it) {
        while (st[it].size() >= 2) {
            int id1 = st[it].back();
            st[it].pop_back();
            int id2 = st[it].back();
            st[it].pop_back();
            int len = 2 * m - have[id1].pos - have[id2].pos;
            if (have[id2].type == 'L') {
                len = m - have[id1].pos + have[id2].pos + m;
            }
            assert(len % 2 == 0);
            ans[have[id1].ind] = len / 2;
            ans[have[id2].ind] = len / 2;
        }
    }
    for (auto i : ans) {
        cout << i << ' ';
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