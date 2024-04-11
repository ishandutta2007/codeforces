#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Seg {
    int l, r, k;
};

bool operator<(Seg a, Seg b) {
    if (a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

set <Seg> data;

int cnt;

void div(int pos) {
    auto it = data.upper_bound({pos, INF, INF});
    if (it == data.begin()) return;
    it--;
    int l = it->l, r = it->r, k = it->k;
    if (l < pos && r >= pos) {
        data.erase({l, r, k});
        data.insert({l, pos - 1, k});
        data.insert({pos, r, k});
    }
}
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
    int n, q;
    cin >> n >> q;
    cnt = n;
    data.insert({1, n, 1});
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        k--;
        div(l);
        div(r + 1);
        while (true) {
            auto it = data.upper_bound({l, -1, 0});
            if (it == data.end()) break;
            if (it->l > r) break;
            if (it->k) {
                cnt -= it->r - it->l + 1;
            }
            data.erase(it);
        }
        data.insert({l, r, k});
        if (k) {
            cnt += r - l + 1;
        }
        cout << cnt << "\n";
    }
}