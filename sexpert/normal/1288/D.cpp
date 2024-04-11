#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 10;
const int MAXN = 3e5 + 10;
vector<vector<int>> v;
int n, m;

pair<int, int> can(int x) {
    int rep[256];
    memset(rep, 0, sizeof rep);
    for(int b = 0; b < n; b++) {
        auto u = v[b];
        int msk = 0;
        for(int i = 0; i < m; i++)
            msk += ((u[i] >= x) << i);
        rep[msk] = b + 1;
    }
    for(int i = 0; i < (1 << m); i++) {
        for(int j = 0; j < (1 << m); j++) {
            if(rep[i] && rep[j] && ((i | j) == ((1 << m)  - 1)))
                return {rep[i], rep[j]};
        }
    }
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        v[i].resize(m);
        for(auto &x : v[i])
            cin >> x;
    }
    int lo = 0, hi = INF;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        auto p = can(mi);
        if(p.first > -1)
            lo = mi;
        else
            hi = mi - 1;
    }
    auto p = can(lo);
    cout << p.first << " " << p.second << '\n';
}