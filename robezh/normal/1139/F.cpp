#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

struct event {
    int type;
    int i, j, k;
};

struct BIT {
    int n;
    vector<int> arr;
    vector<int> bit;

    void init() {
        sort(arr.begin(), arr.end());
        arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
        bit.resize(arr.size(), 0);
        n = bit.size();
    }

    void add(int x, int val) {
        if(x < 0) return ;
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        x = min(x, n - 1);
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

} bit[2];

int n, m;
int p[N], s[N], b[N];
int inc[N], pref[N];
vector<event> evt;
int res[N];

void read(int r[], int k) {
    for(int i = 0; i < k; i++) cin >> r[i];
}

bool cmp(event &e1, event &e2) {
    if(e1.i != e2.i) return e1.i < e2.i;
    return e1.type < e2.type;
}

int lb(int i, int x) {
    return (lower_bound(bit[i].arr.begin(), bit[i].arr.end(), x) - bit[i].arr.begin());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    read(p, n), read(s, n), read(b, n);
    for(int i = 0; i < n; i++) {
        evt.push_back({0, p[i], b[i] + p[i], 1});
        evt.push_back({0, s[i] + 1, b[i] + p[i], -1});
        evt.push_back({1, p[i], b[i] + 1 - p[i], -1});
        evt.push_back({1, s[i] + 1, b[i] + 1 - p[i], 1});
    }
    read(inc, m), read(pref, m);
    for(int i = 0; i < m; i++) {
        evt.push_back({2, inc[i], pref[i], i});
        bit[0].arr.push_back({pref[i] + inc[i]});
        bit[1].arr.push_back({pref[i] - inc[i]});
    }
    for(int i = 0; i < 2; i++) bit[i].init();
    sort(evt.begin(), evt.end(), cmp);
    for(const auto &e : evt) {
        if(e.type == 2) {
            res[e.k] = bit[0].get(lb(0, e.i + e.j)) + bit[1].get(lb(1, e.j - e.i));
        }
        else if(e.type == 0) {
            bit[0].add(lb(0, e.j), e.k);
        }
        else bit[1].add(lb(1, e.j), e.k);
    }
    for(int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }


}