#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct pt{
    int x, y;
    pt() {}
    pt(int _x, int _y) {
        x = _x, y = _y;
    }
};

bool operator<(const pt & a, const pt & b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

int n;

map<int, set<pt>> a;

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        pt x;
        cin >> x.x >> x.y;
        a[x.y - x.x].insert(x);
    }
}

void no() {
    cout << "NO\n";
    exit(0);
}

vector<pt> ans;

void check() {
    set<pt> have;
    for (int i = 0; i < n; i++) {
        bool haveL = have.count(pt(ans[i].x - 1, ans[i].y)) || ans[i].x == 0;
        bool haveR = have.count(pt(ans[i].x, ans[i].y - 1)) || ans[i].y == 0;
        if (!haveL || !haveR) {
            no();
        }
        have.insert(ans[i]);
    }
}

void run() {
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (a[w].empty()) no();
        pt have = *a[w].begin();
        a[w].erase(a[w].begin());
        ans.push_back(have);
    }
    check();
}

void write() {
    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}