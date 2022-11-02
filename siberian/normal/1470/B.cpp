#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

//#define int ll

// mt19937 rnd(time(0));

// bool check(int x) {
//     int a = sqrt(x);
//     a -= 5;
//     chkmax(a, 0);
//     while ((a + 1) * (a + 1) <= x) ++a;
//     return a * a == x; 
// }

// bool check(int a, int b) {
//     assert(__gcd(a, b) != 0);
//     return check((a / __gcd(a, b) * (b / __gcd(a, b))));
// }

// void test() {
//     int n = rnd() % 3 + 1;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         a[i] = (ull)rnd() % 5 + ;
//         assert(a[i] != 0);
//     }

//     cout << "a = ";
//     for (auto i : a) cout << i << " ";
//     cout << endl;
//     int ans = -1;
//     for (int it = 0; it < 5; ++it) {
//         vector<int> na;
//         int have = 0;
//         for (int i = 0; i < n; ++i) {
//             vector<int> x;
//             for (int j = 0; j < n; ++j) {
//                 if (check(a[i], a[j])) {
//                     x.push_back(a[j]);
//                 }
//             }
//             for (auto a : x) {
//                 for (auto b : x) { 
//                     assert(check(a, b));
//                 }
//             }
//             chkmax(have, x.size());
//             int fans = 1;
//             for (auto a : x) {
//                 fans *= a;
//             }
//             na.push_back(fans);
//         }
//         if (ans == -1) {
//             ans = have;
//         } else {
//             if (ans != have){
//                 cout << "na = " << endl;
//                 for (auto i : na) {
//                     cout << i << " ";
//                 }
//                 cout << endl;
//             }
//             assert(ans == have);
//         }
//         a = na;
//         cout << "a = ";
//         for (auto i : a) cout << i << " ";
//         cout << endl;
//     }
// }

const int A = 1e6 + 10;
vector<int> d[A];
// bool isP[A];
bool isSq[A];
vector<int> p;
int lp[A];
vector<int> badDivs[A];

void init() {
    // for (int i = 2; i < A; ++i) {
    //     if (isP[i]) continue;
    //     for (int j = i + i; j < A; j += i) {
    //         isP[j] = true;
    //     }
    // }
    for (int i = 2; i < A; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < p.size() && lp[i] >= p[j] && i * p[j] < A; ++j) {
            lp[i * p[j]] = p[j];
        }
    }
    // map<int, int> cnt;
    for (int i = 2; i < A; ++i) {
        int x = i;
        while (lp[x]) {
            int cnt = 0;
            int now = lp[x];
            while (x % now == 0) {
                cnt ^= 1;
                x /= now;
            }
            if (cnt) {
                badDivs[i].push_back(now);
            }
        }
    }
    // for (int i = 0; i < A; ++i) {
    //     cnt[badDivs[i].size()]++;
    // }
    // for (auto i : cnt) {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;
    // exit(0);

    for (int i = 1; i * i < A; ++i) {
        isSq[i * i] = true;
    }
    for (int i = 1; i < A; ++i) {
        // if (isP[i]) continue;
        for (int j = i; j < A; j += i) {
            if (j % i == 0 && isSq[j / i]) {
                d[j].push_back(i);
            }
        }
    }
}

const int N = 3e5 + 10;
int n;
int a[N];

struct DSU{
    vector<int> par;
    vector<int> sz;
    int n;
    DSU() {}
    DSU(int _n) {
        n = _n;
        par.assign(n, 0);
        iota(all(par), 0);
        sz.assign(n, 1);
    }
    int getPar(int v) {
        if (v == par[v]) return v;
        return par[v] = getPar(par[v]);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a; 
    }
};

int ind[A];
DSU dsu;
    
int calcAns0() {
    dsu = DSU(n);
    for (int i = 0; i < n; ++i) {
        for (auto x : d[a[i]]) {
            if (ind[x] != -1) {
                dsu.uni(ind[x], i);
            } else {
                ind[x] = i;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto x : d[a[i]]) {
            ind[x] = -1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        chkmax(ans, dsu.sz[dsu.getPar(i)]);
    }
    return ans;
}

set<int> have[N];

int calcAns1() {
    // for (int i = 0; i < n; ++i) {
    //     int myInd = dsu.getPar(i);
    //     for (auto x : a[i]) {
    //         if (ind[x] != -1) {
    //             dsu.uni()
    //         }
    //     }
    // }
    for (int i = 0; i < n; ++i) {
        have[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        int myInd = dsu.getPar(i);
        for (auto x : badDivs[a[i]]) {
            if (have[myInd].count(x)) {
                have[myInd].erase(x);
            } else {
                have[myInd].insert(x);
            }
        } 
    }
    map<vector<int>, int> ind;
    set<int> used;
    for (int i = 0; i < n; ++i) {
        int myInd = dsu.getPar(i);
        if (used.count(myInd)) continue;
        used.insert(myInd);

        vector<int> now;
        for (auto x : have[myInd]) {
            now.push_back(x);
        }

        if (ind.find(now) != ind.end()) {
            dsu.uni(ind[now], myInd);
        } else {
            ind[now] = myInd;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        chkmax(ans, dsu.sz[dsu.getPar(i)]);
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans0 = calcAns0();
    int ans1 = calcAns1();

    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        if (w == 0) {
            cout << ans0 << '\n';
        } else {
            cout << ans1 << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    fill(ind, ind + A, -1);
    // for (int it = 0; it < 1000; ++it) {
    //     test();
    //     cerr << "OK " << it << endl;
    // }
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}