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

int query(const vector<int>& a) {
    cout << "? " << a.size();
    for (auto i : a) {
        cout << " " << i;
    }
    cout << endl;
    string ans;
    cin >> ans;
    if (ans == "YES") {
        return 1;
    } else {
        return 0;
    }
}

int query(int val) {
    return query(vector<int>(1, val));
}

void outAns(int val) {
    cout << "! " << val << endl;
    string ans;
    cin >> ans;
    if (ans == ":)") {
        exit(0);
    }
}

int n;
vector<int> a;

void relax() {
    vector<vector<int>> fa(4);
    for (int i = 0; i < (int)a.size(); ++i) {
        fa[i % 4].push_back(a[i]);
    }
    vector<int> first;
    vector<int> second;
    for (auto i : fa[0]) first.push_back(i);
    for (auto i : fa[1]) second.push_back(i);
    for (auto i : fa[2]) first.push_back(i), second.push_back(i);
    int ans_first = query(first);
    int ans_second = query(second);
    vector<bool> ban(4, false);
    if (ans_first && ans_second) {
        ban[3] = true;
    } else if (ans_first && !ans_second) {
        ban[1] = true;
    } else if (!ans_first && ans_second) {
        ban[0] = true;
    } else if (!ans_first && !ans_second) {
        ban[2] = true;
    } else {
        assert(false);
    }
    a.clear();
    for (int i = 0; i < 4; ++i) {
        if (ban[i]) {
            continue;
        }
        for (auto val : fa[i]) {
            a.push_back(val);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    a.assign(n, 0);
    iota(all(a), 1);
    while (a.size() >= 4) {
        relax();
    }
    if (a.size() == 1) {
        outAns(a[0]);
        assert(false);
    } else if (a.size() == 2) {
        outAns(a[0]);
        outAns(a[1]);
        assert(false);
    } else if (a.size() == 3) {
        int first = query(a[0]);
        int second = query(a[1]);
        if (first && second) {
            outAns(a[0]);
            outAns(a[1]);
            assert(false);
        } else if (!first && second) {
            outAns(a[1]);
            outAns(a[2]);
            assert(false);
        } else if (first && !second) {
            outAns(a[0]);
            outAns(a[2]);
            assert(false);
        } else if (!first && !second) {
            int second2 = query(a[1]);
            int first2 = query(a[0]);
            if (second == second2) {
                if (second) {
                    outAns(a[1]);
                    assert(false);
                } else {
                    outAns(a[0]);
                    outAns(a[2]);
                    assert(false);
                }
            } else if (first == first2) {
                if (first) {
                    outAns(a[0]);
                    assert(false);
                } else {
                    outAns(a[1]);
                    outAns(a[2]);
                    assert(false);
                }
            } else {
                assert(false);
            }
        } else {
            assert(false);
        }
    }
    assert(false);
    return 0;
}