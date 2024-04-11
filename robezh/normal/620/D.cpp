#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2005;
const ll INF = (ll)1e18;

struct P{
    ll val;
    int i, j;

    bool operator < (const P &o) const {
        return val <= o.val;
    }
};

int n, m;
int a[N], b[N];
ll asum = 0, bsum = 0;
vector<P> ap, bp;
ll res = INF;
int ai = -1, aj = -1, bi = -1, bj = -1;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], asum += a[i];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) ap.push_back({2LL * (a[i] + a[j]), i, j});
    }
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i], bsum += b[i];
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) bp.push_back({2LL * (b[i] + b[j]), i, j});
    }
    res = abs(asum - bsum);
    sort(bp.begin(), bp.end(), [](const P &a, const P &b) {
        return a.val < b.val;
    });
    if(m >= 2) {
        for(const P &p : ap) {
            auto it = lower_bound(bp.begin(), bp.end(), P{(bsum - asum + p.val), -1, -1});
            ll dif = abs(bsum - asum + p.val - it -> val);
            if(it != bp.end() && dif < res) {
                res = dif;
                ai = p.i, aj = p.j;
                bi = it->i, bj = it->j;
            }
            if(it != bp.begin()) {
                it--;
                dif = abs(bsum - asum + p.val - it -> val);
                if(dif < res) {
                    res = dif;
                    ai = p.i, aj = p.j;
                    bi = it->i, bj = it->j;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ll dif = abs(asum - bsum + 2 * b[j] - 2 * a[i]);
            if(dif < res) {
                res = dif;
                ai = i, aj = -1;
                bi = j, bj = -1;
            }
        }
    }
    vector<pair<int, int> > swa;
    if(ai != -1) swa.push_back({ai, bi});
    if(aj != -1) swa.push_back({aj, bj});
    cout << res << endl;
    cout << swa.size() << endl;
    for(const auto &p : swa) cout << p.first + 1 << " " << p.second + 1 << endl;

}