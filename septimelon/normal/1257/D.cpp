#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = (int)1e9+7;

void smin(int& x, int& y) {
    if (y < x) {
        swap(x, y);
    }
}

int maxind(vector<pii>& s, int val) {
    int l = 0;
    int r = s.size();
    int mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (s[mid].first < val) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (s[0].first >= val) {
        return l;
    }
    return r;
}

void next() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<pii> ps(m);
        for (int i = 0; i < m; ++i) {
            cin >> ps[i].first >> ps[i].second;
        }
        sort(ps.begin(), ps.end());
        for (int i = ps.size() - 2; i >= 0; --i) {
            if (ps[i + 1].second > ps[i].second) {
                ps[i].second = ps[i + 1].second;
            }
        }
        int cind = -1;
        int steps = 0;
        int curv = ps[0].second;
        for (int i = 0; i < n; ++i) {
            int ci = maxind(ps, a[i]);
            if (ci >= ps.size()) {
                cout << "-1\n";
                return;
            }
            curv = min(curv, ps[ci].second);
            if (curv < i - cind) {
                ++steps;
                cind = i - 1;
                curv = ps[ci].second;
            }
        }
        ++steps;
        cout << steps << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        next();
    }

    return 0;
}