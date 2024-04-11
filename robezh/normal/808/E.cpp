#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, m;
int sz[4];
ll w[4][N], psum[4][N];

ll get(int n1, int n2) {
    return psum[1][min(sz[1], n1)] + psum[2][min(sz[2], n2)];
}

ll search(int rem) {
    int l = 0, r = min(sz[2], rem / 2);
//    if(l == r) return get(rem - 2 * l, l);

    while(l + 2 < r) {
        int m1 = l + (r - l) / 3;
        int m2 = l + (r - l) * 2 / 3;
        if(get(rem - 2 * m1, m1) <= get(rem - 2 * m2, m2)) l = m1;
        else r = m2;
    }
    ll res = max(get(rem - 2 * l, l), get(rem - 2 * r, r));
    if(l + 2 == r) res = max(res, get(rem - 2 * (l + 1), l + 1));
    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int wi, c; cin >> wi >> c;
        w[wi][++sz[wi]] = c;
    }
    for(int wi = 1; wi <= 3; wi++) {
        psum[wi][0] = 0;
        sort(w[wi] + 1, w[wi] + sz[wi] + 1, greater<>());
        for(int j = 1; j <= sz[wi]; j++) psum[wi][j] = psum[wi][j-1] + w[wi][j];
    }
    ll res = 0;
    for(int i = 0; i <= sz[3] && 3 * i <= m; i++) {
        int remm = m - 3 * i;
        res = max(search(remm) + psum[3][i], res);
    }
    cout << res << endl;
}