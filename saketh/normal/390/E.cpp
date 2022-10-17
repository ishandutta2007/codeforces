#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e6 + 500;

struct bit
{
    int n;
    ll B[MAXN] , cols[MAXN];
    void init(int size) {
        n = size;
        memset(B , 0 , sizeof(B));
        memset(cols , 0 , sizeof(cols));
    }
    bit() {}
    bit(int size) {
        init(size);
    }
    void _add(ll* c , int x , ll w) {
        for ( ; x <= n ; x += x & -x)
            c[x] += w;
    }
    ll _sum(ll* c , int x) {
        ll res = 0;
        for ( ; x > 0 ; x -= x & -x)
            res += c[x];
        return res;
    }
    void add(int l , int r , ll w) {
        _add(B , l , w) , _add(B , r + 1 , -w);
        _add(cols , l , w * l) , _add(cols , r + 1 , -w * (r + 1));
    }
    ll sum(int l , int r) {
        ll res = 0;
        res += (r + 1) * _sum(B , r) - l * _sum(B , l - 1);
        res -= _sum(cols , r) - _sum(cols , l - 1);
        return res;
    }
} rows, cols;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M, W, t, x1, y1, x2, y2, v;
    
    cin >> N >> M >> W;

    rows.init(N);
    cols.init(M);

    for (int i = 0; i < W; i++) {
        cin >> t >> x1 >> y1 >> x2 >> y2;

        if (t == 0) {
            cin >> v;
            rows.add(x1, x2, v * 1ll * (y2 - y1 + 1));
            cols.add(y1, y2, v * 1ll * (x2 - x1 + 1));
        } else {
            ll plus = rows.sum(x1, x2) + cols.sum(y1, y2);

            ll minus = rows.sum(0, x1-1) + rows.sum(x2+1, N)
                     + cols.sum(0, y1-1) + cols.sum(y2+1, M);

            cout << (plus - minus) / 2 << "\n";
        }
    }
}