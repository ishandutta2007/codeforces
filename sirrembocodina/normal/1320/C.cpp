#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int TREE_SIZE = 525000;

vector<int> mx(TREE_SIZE);
vector<int> buf(TREE_SIZE);

void build_tree(vector<pair<int, int>>& a, int v, int l, int r) {
    if (l == r - 1) {
        mx[v] = -a[l].second;
        return;
    }
    int m = (l + r) / 2;
    build_tree(a, 2 * v + 1, l, m);
    build_tree(a, 2 * v + 2, m, r);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

void update(int v, int l, int r) {
    mx[v] += buf[v];
    if (l < r - 1) {
        buf[2 * v + 1] += buf[v];
        buf[2 * v + 2] += buf[v];
    }
    buf[v] = 0;
}

void add_seg(int v, int l, int r, int L, int R, int x) {
    update(v, l, r);
    if (r <= L || R <= l) {
        return;
    }
    if (L <= l && r <= R) {
        buf[v] += x;
        update(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    add_seg(2 * v + 1, l, m, L, R, x);
    add_seg(2 * v + 2, m, r, L, R, x);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    forn (i, n) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    build_tree(a, 0, 0, n);
    vector<pair<int, pair<int, int>>> q; // x, t, ind
    vector<pair<int, int>> b(m);
    forn (i, m) {
        cin >> b[i].first >> b[i].second;
        q.push_back({b[i].first, {0, i}});
    }
    vector<pair<pair<int, int>, int>> c(k);
    forn (i, k) {
        cin >> c[i].first.first >> c[i].first.second >> c[i].second;
        q.push_back({c[i].first.second, {1, i}});
    }
    sort(q.begin(), q.end());
    int ans = -2e18;
    //cerr << mx[0] << endl;
    forn (i, q.size()) {
        int ind = q[i].second.second;
        if (q[i].second.first == 1) {
            int up = upper_bound(a.begin(), a.end(), make_pair(c[ind].first.first, (int)(2e9))) - a.begin();
            //cerr << "+ " << c[ind].second << " from " << up << endl;
            add_seg(0, 0, n, up, n, c[ind].second);
        } else {
            ans = max(ans, mx[0] - b[ind].second);
        }
        //cerr << q[i].second.first << " " << ind << endl;
        //cerr << mx[0] << endl;
        //cerr << ans << endl;
    }
    cout << ans << endl;
}