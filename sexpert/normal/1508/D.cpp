#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point {
    ll x, y;
    point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    point operator- (const point &o) const { return point(x - o.x, y - o.y); }
    int half() { return y < 0 || (y == 0 && x < 0); }
};

ll cross(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

bool cmp(point p, point q) {
    if(p.half() != q.half()) {
        return p.half() < q.half();
    }
    return cross(p, q) > 0;
}

const int MAXN = 2005;
point ps[MAXN];
int n, a[MAXN], cyc[MAXN];
vector<int> in_cyc[MAXN];
vector<array<int, 2>> ops;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ps[i].x >> ps[i].y >> a[i];
    }

    int cur_cyc = 0, piv = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == i || cyc[i])
            continue;
        cur_cyc++;
        int u = i;
        do {
            cyc[u] = cur_cyc;
            in_cyc[cur_cyc].push_back(u);
            u = a[u];
        } while(!cyc[u]);
        piv = i;
    }

    vector<int> to_sort;
    for(int i = 1; i <= n; i++) {
        if(a[i] == i || i == piv)
            continue;
        to_sort.push_back(i);
    }
    if(to_sort.empty()) {
        cout << "0\n";
        return 0;
    }

    sort(to_sort.begin(), to_sort.end(), [&](int i, int j){ return cmp(ps[i] - ps[piv], ps[j] - ps[piv]); } );
    vector<array<int, 2>> pairs;
    to_sort.push_back(to_sort[0]);
    
    for(int i = 0; i + 1 < to_sort.size(); i++) {
        if(cross(ps[to_sort[i]] - ps[piv], ps[to_sort[i + 1]] - ps[piv]) > 0)
            pairs.push_back({to_sort[i], to_sort[i + 1]});
    }
    for(auto &[i, j] : pairs) {
        int c1 = cyc[i], c2 = cyc[j];
        if(c1 != c2) {
            for(auto &x : in_cyc[c2]) {
                cyc[x] = c1;
                in_cyc[c1].push_back(x);
            }
            in_cyc[c2].clear();
            ops.push_back({i, j});
            swap(a[i], a[j]);
        }
    }

    while(a[piv] != piv) {
        int u = a[piv];
        ops.push_back({piv, u});
        swap(a[piv], a[u]);
    }

    cout << ops.size() << '\n';
    for(auto &[i, j] : ops)
        cout << i << " " << j << '\n';
}