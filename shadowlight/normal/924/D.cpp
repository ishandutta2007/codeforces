#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-13;

struct Tree {
    int n;
    vector <int> t;
    Tree(int n) : n(n), t(2 * n, 0) {}
    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2) {
                res += t[l++];
            }
            if (r % 2 == 0) {
                res += t[r--];
            }
        }
        return res;
    }
    void add(int v) {
        v += n;
        t[v]++;
        v /= 2;
        while (v) {
            t[v] = t[2 * v] + t[2 * v + 1];
            v /= 2;
        }
    }
};

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    double w;
    cin >> n >> w;
    vector <pair <double, int> > ax, ay;
    for (int i = 0; i < n; i++) {
        double x, v;
        cin >> x >> v;
        double xt = x / (v - w);
        double yt = x / (v + w);
        //cout << xt << " " << yt << "\n";
        ax.push_back({xt, i});
        ay.push_back({yt, i});
    }
    sort(ax.begin(), ax.end());
    sort(ay.begin(), ay.end());
    vector <pair <int, int> > pos(n);
    int lastx = 0, lasty = 0;
    for (int i = 0; i < n; i++) {
        pos[ax[i].second].first = lastx;
        pos[ay[i].second].second = -lasty;
        if (i < n - 1 && abs(ax[i + 1].first - ax[i].first) > EPS) {
            lastx++;
        }
        if (i < n - 1 && abs(ay[i + 1].first - ay[i].first) > EPS) {
            lasty++;
        }
    }
    ll res = 0;
    Tree t(n);
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; i++) {
        //cout << pos[i].first << " " << -pos[i].second << "\n";
        res += t.get(-pos[i].second, n - 1);
        t.add(-pos[i].second);
    }
    cout << res;
}