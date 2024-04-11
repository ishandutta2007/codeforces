#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50, INF = (int)1e9 + 50;


int val[N];

struct P {
    int l, r;
} p[N][2];

int n, m;
int to[N][2];
int dp[N][2], gd[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> val[i];
        rep(b, 0, 2) cin >> p[i][b].l >> p[i][b].r;
    }

    rep(b, 0, 2) {
        vector<pii> S;
        S.push_back({INF, n + 1});
        for(int i = n; i >= 0; i--) {
            while(!S.empty() && S.back().first <= p[i][b].l) S.pop_back();
            S.push_back({p[i][b].l, i});

            int l = 0, r = sz(S), mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(S[mid].first <= val[i]) r = mid;
                else l = mid;
            }

//            int s = i;
//            while(s <= n && val[i] >= p[s][b].l) s++;
//            cout << i << " " << s << " " << S[l].second << endl;
//            assert(S[l].second == s);

            to[i][b] = S[l].second;

        }
        S.clear();
        S.push_back({-INF, n + 1});
        for(int i = n; i >= 0; i--) {
            while(!S.empty() && S.back().first >= p[i][b].r) S.pop_back();
            S.push_back({p[i][b].r, i});

            int l = 0, r = sz(S), mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(S[mid].first >= val[i]) r = mid;
                else l = mid;
            }

//            int s = i;
//            while(s <= n && val[i] <= p[s][b].r) s++;
////            cout << i << " " << s << " " << S[l].second << endl;
//            assert(S[l].second == s);

            to[i][b] = min(to[i][b], S[l].second);
        }

    }

    dp[n + 1][0] = n + 1;
    dp[n + 1][1] = n + 1;
    for(int i = n; i >= 1; i--) {
        rep(b, 0, 2) {
            dp[i][b] = INF;
            if(to[i][b] > i) {
                dp[i][b] = min(dp[i][b], dp[i + 1][b]);
            }
            if(to[i][b] >= dp[i + 1][!b]) {
                dp[i][b] = min(dp[i][b], i + 1);
            }
//            cout << i << " " << b << " " << dp[i][b] << endl;
        }
    }
    int cur = 1, b;
    if(to[0][0] >= dp[1][1] || to[0][1] >= dp[1][0]) {
        b = to[0][0] >= dp[1][1];
        cout << "Yes\n";
        while(cur <= n) {
            int nxt = dp[cur][b];
//            cout << cur << " " << b << " " << nxt << endl;
            rep(i, 0, nxt - cur) cout << b << " ";

            cur = nxt;
            b = !b;
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    };





}