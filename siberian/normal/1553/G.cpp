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

struct Dsu{
    vector<int> par;
    Dsu() {}
    Dsu(int n) {
        par.assign(n, 0);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) return v;
        return par[v] = getPar(par[v]);
    }
    bool connect(int a, int b) {
        return getPar(a) == getPar(b);
    }
    void uni(int a, int b) {
        par[getPar(a)] = getPar(b);
    } 
};

const int C = 1e6 + 10;

int lp[C];
vector<int> p;

void initP() {
    for (int i = 2; i < C; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= lp[i] && i * p[j] < C; ++j) {
            lp[i * p[j]] = p[j];
        }
    }
}

const int N = 2e5 + 10;

int n;
int a[N];

vector<int> fact(int x) {
    vector<int> ans;
    while (x > 1) {
        ans.push_back(lp[x]);
        x /= lp[x];
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    return ans;
}

vector<pair<int, int>> edges;

void addEdge(int a, int b) {
    if (a > b) swap(a, b);
    edges.push_back({a, b});
}

bool connect(int a, int b) {
    if (a > b) swap(a, b);
    return binary_search(all(edges), make_pair(a, b));
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    initP();
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Dsu dsu(C + n);
    for (int i = 0; i < n; ++i) {
        auto have = fact(a[i]);
        for (auto x : have) {
            // cerr << "x = " << x << " i = " << i << endl;
            dsu.uni(x, C + i);
        }
    }
    for (int i = 0; i < n; ++i) {
        auto haveA = fact(a[i]);
        auto haveB = fact(a[i] + 1);

        for (auto i : haveA) haveB.push_back(i);

        // for (auto x : haveB) {
        //     for (auto y : haveB) {
        for (int it1 = 0; it1 < haveB.size(); ++it1) {
            for (int it2 = it1; it2 < haveB.size(); ++it2) {
                int x = haveB[it1];
                int y = haveB[it2];
                // if (i == 1) {
                //     cout <<"x = " << x << " y = " << y << endl;
                // }
                addEdge(dsu.getPar(i + C), dsu.getPar(x));
                // addEdge(dsu.getPar(i + C), dsu.getPar(y));
                addEdge(dsu.getPar(y), dsu.getPar(x));
            }
        }
    }
    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (dsu.connect(C + a, C + b)) {
            cout << "0\n";
        } else if (connect(dsu.getPar(C + a), dsu.getPar(C + b))) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}