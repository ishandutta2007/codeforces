#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e3, M = (int)1e5, MID = M / 2;
typedef pair<vi, vi> pvi;

int h, v;
int a[N], b[N];
bool dp[N][M], up[N][M];

pvi make_part(int *val, int n) {
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + M, false);
    dp[0][MID] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < M; j++) {
            if(!dp[i][j]) continue;
            if(j >= val[i]) dp[i + 1][j - val[i]] = 1, up[i + 1][j - val[i]] = false;
            if(j + val[i] < M) dp[i + 1][j + val[i]] = 1, up[i + 1][j + val[i]] = true;
        }
    }
    if(!dp[n][MID]) return {vi(), vi()};
    vi v1, v2;
    int cur = MID;
    for(int i = n; i >= 1; i--) {
        if(up[i][cur]) v1.push_back(val[i - 1]), cur -= val[i - 1];
        else v2.push_back(val[i - 1]), cur += val[i - 1];
    }
    return {v1, v2};
}

mt19937 rng(2333);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> h;
        rep(i, 0, h) cin >> a[i];
        cin >> v;
        rep(i, 0, v) cin >> b[i];
        shuffle(a, a + h, rng);
        shuffle(b, b + v, rng);
        pvi ap = make_part(a, h);
        pvi bp = make_part(b, v);
        if(ap.first.empty() || bp.first.empty() || h != v) {
            cout << "No\n";
            continue;
        }
        if(sz(ap.first) > sz(ap.second)) swap(ap.first, ap.second);
        if(sz(bp.first) > sz(bp.second)) swap(bp.first, bp.second);
        int swapped = sz(ap.first) > sz(bp.first);
        if(swapped) swap(ap, bp);

        sort(all(ap.first));
        sort(all(ap.second));
        sort(all(bp.first));
        sort(all(bp.second));
        vector<pii> res;
        int cx = 0, cy = 0;
        int len0 = sz(ap.first), len1 = sz(bp.second), len_mid = sz(bp.first) - len0;
        for(int i = 0; i < len0; i++) {
            cx -= ap.first[len0 - 1 - i];
            res.push_back({cx, cy});
            cy -= bp.first[i];
            res.push_back({cx, cy});
        }
//        cout << swapped << endl;
        for(int i = 0; i < len_mid; i++) {
            cx += ap.second[len1 + i];
            res.push_back({cx, cy});
            cy -= bp.first[len0 + i];
            res.push_back({cx, cy});
        }

        for(int i = 0; i < len1; i++) {
            cx += ap.second[len1 - 1 - i];
            res.push_back({cx, cy});
            cy += bp.second[i];
            res.push_back({cx, cy});
        }
        cout << "Yes\n";

        for(auto &p : res) {
            if(swapped) swap(p.first, p.second);
            cout << p.first << " " << p.second << '\n';
        }
    }

}