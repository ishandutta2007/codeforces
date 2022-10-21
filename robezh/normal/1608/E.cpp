#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50, X = (int)1e9;

int n;
int x[N], y[N], d[N], c[N];
int ix[N], iy[N];

bool check(int k) {
    int cnt = 0;
    int rx = -X - 1;
    rep(j, 0, n) {
        int i = ix[j];
        if(d[i] == 0) {
            rx = x[i];
            if(++cnt == k) break;
        }
    }
    cnt = 0;
    int ct = 1;
    int r = 0;
    for (int i = 0; i < n; i = r) {
        while(r < n && y[iy[r]] == y[iy[i]]) {
            if(ct == d[iy[r]] && x[iy[r]] > rx) cnt++;
            r++;
        }
        if(cnt >= k) ct++, cnt = 0;
    }
    return ct == 3;
}

bool check2(int k) {
    int cnt = 0;
    int ct = 0;

    int r = 0;
    for (int i = 0; i < n; i = r) {
        while(r < n && x[ix[r]] == x[ix[i]]) {
            if(ct == d[ix[r]]) cnt++;
            r++;
        }
        if(cnt >= k) cnt = 0, ct++;
    }
    return ct == 3;
}

void flip_x() {
    rep(i, 0, n) x[i] = - x[i];
    reverse(ix, ix + n);
}

void swap_xy() {
    rep(i, 0, n) {
        swap(ix[i], iy[i]);
        swap(x[i], y[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> x[i] >> y[i] >> c[i], c[i]--;

    iota(ix, ix + n, 0);
    iota(iy, iy + n, 0);
    sort(ix, ix + n, [&](const int i, const int j) {
        return x[i] < x[j];
    });
    sort(iy, iy + n, [&](const int i, const int j) {
        return y[i] < y[j];
    });

    int res = 0;


    rep(swapped, 0, 2) {
        if (swapped) swap_xy();
        // "T" shape
        rep(fx, 0, 2) {
            if (fx) flip_x();
            vi per = {0, 1, 2};
            do {
                rep(i, 0, n) d[i] = per[c[i]];
                int l = 0, r = n / 3 + 1, mid;
                while (l + 1 < r) {
                    mid = (l + r) / 2;
                    if (check(mid)) l = mid;
                    else r = mid;
                }
                res = max(res, l);
            } while (next_permutation(all(per)));

            if (fx) flip_x();
        }
        // in a row
        vi per = {0, 1, 2};
        do {
            rep(i, 0, n) d[i] = per[c[i]];
            int l = 0, r = n / 3 + 1, mid;
            while (l + 1 < r) {
                mid = (l + r) / 2;
                if (check2(mid)) l = mid;
                else r = mid;
            }
            res = max(res, l);
        } while (next_permutation(all(per)));
        if (swapped) swap_xy();
    }
    cout << res * 3 << '\n';
}