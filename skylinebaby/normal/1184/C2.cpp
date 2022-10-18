#include <bits/stdc++.h>
using namespace std;

int seg[5000005 * 4][2];

void pull(int o) {
    seg[o][0] = max(seg[o * 2 + 1][0], seg[o * 2 + 2][0]);
}

void add(int o, int x) {
    seg[o][0] += x;
    seg[o][1] += x;
}

void push(int o) {
    add(o * 2 + 1, seg[o][1]);
    add(o * 2 + 2, seg[o][1]);
    seg[o][1] = 0;
}

pair<int, int> ps[300005];
vector<pair<int, pair<int, int>>> ev[6000007];

#define mid ((l + r) >> 1)
void build(int o, int l, int r) {
    if (l == r) return;
    build(o * 2 + 1, l , mid);
    build(o * 2 + 2, mid + 1, r);
}

void modify(int o, int l, int r, int ml, int mr, int x) {
    if (r < ml || mr < l) return;
    if (ml <= l && r <= mr) return add(o, x), void();
    push(o);
    modify(o * 2 + 1, l, mid, ml, mr, x);
    modify(o * 2 + 2, mid + 1, r, ml, mr, x);
    pull(o);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, r; cin >> n >> r;
    for (int i = 0; i < n; ++i) cin >> ps[i].first >> ps[i].second, ps[i].first += 1000001, ps[i].second += 1000001, 
        tie(ps[i].first, ps[i].second) = make_pair(ps[i].first + ps[i].second, ps[i].first - ps[i].second),
        ps[i].first += 1000001, ps[i].second += 3000001, // (3000000, 5000000)
        ev[ps[i].first - r].emplace_back(1, make_pair(ps[i].second - r, ps[i].second + r)),
        ev[ps[i].first + r + 1].emplace_back(-1, make_pair(ps[i].second - r, ps[i].second + r));
    build(0, 1, 5000001);
    int mx = 1;
    for (int i = 0; i < 6000007; ++i) {
        for (auto &p : ev[i])
            modify(0, 1, 5000001, p.second.first, p.second.second, p.first);
        mx = max(mx, seg[0][0]);
    }
    cout << mx << endl;
}