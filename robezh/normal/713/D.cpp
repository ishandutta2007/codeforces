#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int B = 10, N = 1002;

int n, m, a[N][N];
int st[B][B][N][N];
int lg[N];
int psum[N][N];

bool is_square(int x, int y, int l) {
    return psum[x + l - 1][y + l - 1] - psum[x - 1][y + l - 1]
            - psum[x + l - 1][y - 1] + psum[x - 1][y - 1] == l * l;
}

int rmq(int x1, int y1, int x2, int y2) {
    int lgx = lg[x2 - x1 + 1], lgy = lg[y2 - y1 + 1];
    int x3 = x2 - (1 << lgx) + 1, y3 = y2 - (1 << lgy) + 1;
    auto d = st[lgx][lgy];
//    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << max({d[x1][y1], d[x1][y3], d[x3][y1], d[x3][y3]}) << endl;
    return max({d[x1][y1], d[x1][y3], d[x3][y1], d[x3][y3]});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, N) {
        int b = 0, x = i;
        while(x > 1) x /= 2, b++;
        lg[i] = b;
    }
    cin >> n >> m;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> a[i][j];
            psum[i][j] = a[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            int l = 0, r = min(n - i + 1, m - j + 1) + 1, mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(is_square(i, j, mid)) l = mid;
                else r = mid;
            }
            st[0][0][i][j]= l;
//            cout << l << " ";
        }
//        cout << endl;
    }
    rep(bn, 0, B) {
        rep(bm, 0, B) {
            if(bn == 0 && bm == 0) continue;
            if(bn == 0) {
                for(int i = 1; i + (1 << bn) - 1 <= n; i++) {
                    for (int j = 1; j + (1 << bm) - 1 <= m; j++) {
                        st[bn][bm][i][j] = max(st[bn][bm - 1][i][j], st[bn][bm - 1][i][j + (1 << (bm - 1))]);
                    }
                }
            } else {
                for(int i = 1; i + (1 << bn) - 1 <= n; i++) {
                    for (int j = 1; j + (1 << bm) - 1 <= m; j++) {
                        st[bn][bm][i][j] = max(st[bn - 1][bm][i][j], st[bn - 1][bm][i + (1 << (bn - 1))][j]);
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1) + 1, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(rmq(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid) l = mid;
            else r = mid;
        }
        cout << l << '\n';
    }




}