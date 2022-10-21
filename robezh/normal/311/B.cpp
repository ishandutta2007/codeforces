#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
const int N = (int)1e5 + 50, K = 105;
const ll INF = (ll)1e18;

int n, m, p;
int d[N];
int h[N], t[N];

struct Line {
    ll k, m;
    Line(ll _k, ll _m) {
        k = _k, m = _m;
    }
    Pll inter(Line o) {
        return {m - o.m, o.k - k};
    }
};


struct HULL {
    deque<Line> que;

    bool leq(Pll a, Pll b) {
        return a.first * b.second <= a.second * b.first;
    }

    void add(ll k, ll m) {
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(leq(que[ls].inter(Line(k, m)), que[ls-1].inter(que[ls]))) que.pop_back();
            else break;
        }
        que.push_back({k, m});
    }

//    ll query(ll x) {
//        int l = 0, r = que.size() - 1;
//        while(l < r) {
//            int mi = (l + r) / 2;
//            if(que[mi].k * x + que[mi].m < que[mi+1].k * x + que[mi+1].m) l = mi + 1;
//            else r = mi;
//        }
//        return que[l].k * x + que[l].m;
//    }

    ll query(ll x) {
        while(que.size() > 1) {
            if(que[0].k * x + que[0].m < que[1].k * x + que[1].m) que.pop_front();
            else break;
        }
        return que[0].k * x + que[0].m;
    }

} hull[2];

ll psum[N];
ll dp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    for(int i = 1; i < n; i++) cin >> d[i];
    for(int i = 1; i < n; i++) d[i] += d[i-1];
    for(int i = 1; i <= m; i++) {
        cin >> h[i] >> t[i];
        h[i]--;
        t[i] -= d[h[i]];
    }
    sort(t + 1, t + m + 1);
    for(int i = 1; i <= m; i++) psum[i] = psum[i-1] + t[i];
    int nw = 1, la = 0;
    hull[nw].add(0, 0);
    ll res = INF;
    for(int k = 1; k <= p; k++) {
        swap(nw, la);
        hull[nw].que.clear();
        hull[nw].add(0, 0);
        for(int i = 1; i <= m; i++) {
            dp[nw][i] = -hull[la].query(t[i]) + 1LL * i * t[i] - psum[i];
            hull[nw].add(i, -(dp[nw][i] + psum[i]));
        }
//        cout << k << ": " << endl;
//        for(int i = 1; i <= m; i++) cout << i << ": " << dp[nw][i] << ", ";
//        cout << endl;
        res = min(res, dp[nw][m]);
    }
    cout << res << endl;

}