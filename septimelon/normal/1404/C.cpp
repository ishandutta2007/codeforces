#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

vector<int> tot;

void incr(int i, int cl, int cr, int ci) {
    if (cr == cl + 1) {
        //cout << cl << "| ";
        ++tot[ci];
        return;
    }
    int mid = (cl + cr) / 2;
    if (i < mid) {
        incr(i, cl, mid, ci * 2 + 1);
    }
    else {
        incr(i, mid, cr, ci * 2 + 2);
    }
    tot[ci] = tot[ci * 2 + 1] + tot[ci * 2 + 2];
}

void upgr(int minv, int cl, int cr, int ci) {
    if (tot[ci] < minv) {
        //cout << "! ";
        return;
    }
    if (cr == cl + 1) {
        //cout << cl << " ";
        ++tot[ci];
        return;
    }
    int mid = (cl + cr) / 2;
    if (tot[ci * 2 + 2] < minv) {
        upgr(minv - tot[ci * 2 + 2], cl, mid, ci * 2 + 1);
    }
    else {
        upgr(minv, mid, cr, ci * 2 + 2);
    }
    tot[ci] = tot[ci * 2 + 1] + tot[ci * 2 + 2];
}

int gets(int l, int r, int cl, int cr, int ci) {
    if (l == cl && r == cr) {
        return tot[ci];
    }
    if (r <= l) {
        return 0;
    }
    int mid = (cl + cr) / 2;
    int cs = gets(max(l, cl), min(r, mid), cl, mid, ci * 2 + 1);
    cs += gets(max(l, mid), min(r, cr), mid, cr, ci * 2 + 2);
    return cs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    tot.assign(n * 4 + 5, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= (i + 1);
        //cout << a[i] << " ";
    }
    //cout << "\n";
    vector<pair<pair<int, int>, int>> rl;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        rl.push_back({ { n - y - 1, x }, i });
    }
    sort(rl.begin(), rl.end());
    rl.push_back({ {INF, INF}, 0 });
    vector<int> ans(q);

    int cj = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            incr(i, 0, n, 0);
        }
        else if (a[i] < 0) {
            upgr(0 - a[i], 0, n, 0);
        }
        while (i == rl[cj].first.first) {
            ans[rl[cj].second] = gets(rl[cj].first.second, i + 1, 0, n, 0);
            ++cj;
        }
    }
    /*cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << gets(i, i + 1, 0, n, 0) << " ";
    }
    cout << "\n";
    for (int i = 0; i < tot.size(); ++i) {
        cout << tot[i] << " ";
    }
    cout << "\n";*/

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}