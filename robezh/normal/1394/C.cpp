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

const int N = (int)3e5 + 50, INF = (int)1e9;
int n;
string str[N];
int cnt[N][2];

pii solve(int len) {
    int xl = 0, xr = INF, yl = 0, yr = INF, dl = -INF, dr = INF;
    rep(i, 0, n) {
        xl = max(xl, cnt[i][0] - len);
        xr = min(xr, cnt[i][0] + len);
        yl = max(yl, cnt[i][1] - len);
        yr = min(yr, cnt[i][1] + len);
        dl = max(dl, cnt[i][0] - cnt[i][1] - len);
        dr = min(dr, cnt[i][0] - cnt[i][1] + len);
    }
    if(xl > xr || yl > yr || dl > dr) return {-1, -1};
    if(xl - yr > dr || xr - yl < dl) return {-1, -1};
    int d = dr <= xr - yl ? dr : dl;
    int x = min(xr, yr + d), y = x - d;
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> str[i];
        for (char &c : str[i]) cnt[i][c == 'N']++;
    }
    int l = -1, r = (int)2e6, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(solve(mid).first != -1) r = mid;
        else l = mid;
    }
    pii p = solve(r);
    cout << r << '\n';
    
    rep(i, 0, p.first) cout << "B";
    rep(i, 0, p.second) cout << "N";
    cout << '\n';


}