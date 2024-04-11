#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50, Q = 5005;

struct Rec {
    int in;
    double p;
    int idx;
};

vector<Rec> rc[N];

int n, q;
int a[N];
double dp[Q][2 * Q];
pii ps[N];
int mxval[Q];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    int mx = 0;
    rep(i, 0, n) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    rep(i, 0, q) {
        int l, r; double p;
        cin >> l >> r >> p; l--, r--;
        rc[l].push_back({1, p, i});
        rc[r].push_back({0, p, i});
        ps[i] = {l, r};
    }

    rep(i, 0, n) {
        sort(all(rc[i]), [](const Rec &r1, const Rec &r2) {
            if(r1.in != r2.in) return r1.in > r2.in;
            if(ps[r1.idx] == ps[r2.idx]) {
                if(r1.in) return r1.idx < r2.idx;
                else return r1.idx > r2.idx;
            }
            if(r1.in) return ps[r1.idx].first <= ps[r2.idx].first && ps[r2.idx].second <= ps[r1.idx].second;
            else return ps[r1.idx].first >= ps[r2.idx].first && ps[r2.idx].second >= ps[r1.idx].second;
        });
    }

    rep(i, 0, n) {
        if(a[i] > mx - q) a[i] -= (mx - q);
        else a[i] = 0;
    }

    for(int i = 0; i <= q; i++) fill(dp[i], dp[i] + 2 * q + 1, 1);
    fill(mxval, mxval + Q, -1);

    stack<int> S;
    S.push(q);
    for(int i = 0; i < n; i++) {
        for(auto p : rc[i]) {
            if(p.in) S.push(p.idx);
        }

        mxval[S.top()] = max(mxval[S.top()], a[i]);
        for(auto r : rc[i]) {
            if(r.in) continue;
            assert(S.top() == r.idx);
            for(int m = 2 * q; m >= 0; m--) {
                double cdp = dp[r.idx][m] * (1 - r.p) * (mxval[r.idx] <= m);
                if(m > 0) cdp += dp[r.idx][m - 1] * r.p * (mxval[r.idx] + 1 <= m);
                dp[r.idx][m] = cdp;
            }
            S.pop();
            for(int m = 0; m <= 2 * q; m++) {
                dp[S.top()][m] *= dp[r.idx][m];
            }
        }
    }

    double fres = 0;
    rep(i, 0, mxval[q]) dp[q][i] = 0;
    rep(i, 1, 2 * q + 1) {
        fres += i * (dp[q][i] - dp[q][i - 1]);
    }
    fres += mx - q;
    cout << fixed << setprecision(10) << fres << '\n';

}