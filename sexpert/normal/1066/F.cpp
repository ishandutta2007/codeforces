#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;

const int MAXN = 2e5 + 5;

ll dist(pt a, pt b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool cmp(pt a, pt b) {
    if(max(a.first, a.second) == max(b.first, b.second)) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    return max(a.first, a.second) < max(b.first, b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll dp[MAXN][2];
    vector<pt> pts;
    map<ll, ll> levels;
    vector<pt> bylevel[MAXN];
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pts.push_back(make_pair(x, y));
    }
    pts.push_back(make_pair(0, 0));
    sort(pts.begin(), pts.end(), cmp);
    int nlevels = 0;
    for(int i = 0; i < pts.size(); i++) {
        if(i == 0 || max(pts[i].first, pts[i].second) > max(pts[i - 1].first, pts[i - 1].second))
            levels[max(pts[i].first, pts[i].second)] = nlevels++;
    }
    for(auto p : pts)
        bylevel[levels[max(p.first, p.second)]].push_back(p);
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i < nlevels; i++) {
        pt fi = bylevel[i][0], la = bylevel[i][bylevel[i].size() - 1];
        ll inlevel = dist(fi, la);
        int nPrev = bylevel[i - 1].size();
        ll minFi = min(dp[i - 1][0] + dist(bylevel[i - 1][0], fi), dp[i - 1][1] + dist(bylevel[i - 1][nPrev - 1], fi));
        ll minLa = min(dp[i - 1][0] + dist(bylevel[i - 1][0], la), dp[i - 1][1] + dist(bylevel[i - 1][nPrev - 1], la));
        dp[i][0] = minLa + inlevel;
        dp[i][1] = minFi + inlevel;
    }
    cout << min(dp[nlevels - 1][0], dp[nlevels - 1][1]) << endl;
}