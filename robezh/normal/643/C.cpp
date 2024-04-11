/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description: Maintaining upper convex hull, querying the maximum. Need to put in lines in strictly increasing order of slope.
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pd;
const double INF = 1e18;
const int N = (int)2e5 + 50, K = 51;

struct Line {
    double k, m;
    Line(double _k, double _m) {
        k = _k, m = _m;
    }
    pd inter(Line o) {
        return {m - o.m, o.k - k};
    }
};


struct Hull {
    deque<Line> que;

    bool leq(pd a, pd b) {
        return a.first * b.second <= a.second * b.first;
    }
    // k needs to be strictly increasing!
    void add(double k, double m) {
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(leq(que[ls].inter(Line(k, m)), que[ls-1].inter(que[ls]))) que.pop_back();
            else break;
        }
        que.push_back({k, m});
    }
    // Arbitrary x.
    double query_bin(double x) {
        if(que.empty()) return -INF;
        int l = 0, r = que.size() - 1;
        while(l < r) {
            int mi = (l + r) / 2;
            if(que[mi].k * x + que[mi].m < que[mi+1].k * x + que[mi+1].m) l = mi + 1;
            else r = mi;
        }
        return que[l].k * x + que[l].m;
    }
    // If querying increasing x.
    double query(double x) {
        if(que.empty()) return -INF;
        while(que.size() > 1) {
            if(que[0].k * x + que[0].m < que[1].k * x + que[1].m) que.pop_front();
            else break;
        }
        return que[0].k * x + que[0].m;
    }

};

int n, k;
int t[N];
double dp[2][N];
double sum[N], invsum[N], trisum[N];
double sqsum[N];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        sum[i] = t[i] + sum[i-1];
        invsum[i] = 1.0 / t[i] + invsum[i-1];
        trisum[i] = sum[i] / t[i] + trisum[i-1];
        sqsum[i] = sum[i] * invsum[i];
    }
    int nw = 0, la = 1;
    for(int i = 0; i < 2; i++) fill(dp[i], dp[i] + n + 1, INF);
    dp[nw][0] = 0;
    for(int c = 1; c <= k; c++) {
        swap(nw, la);
        fill(dp[nw], dp[nw] + n + 1, INF);
        Hull hull;
        for(int i = 1; i <= n; i++) {
            if(dp[la][i-1] != INF) hull.add(sum[i-1], -(dp[la][i-1] - trisum[i-1] + sqsum[i-1]));
            dp[nw][i] = -hull.query(invsum[i]) + trisum[i];
        }
    }
    cout << fixed << setprecision(10) << dp[nw][n] << endl;
}