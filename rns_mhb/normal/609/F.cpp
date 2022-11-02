#include <bits/stdc++.h>
using namespace std;

#define N 200005

typedef long long ll;
typedef pair<ll, int> pli;
const int INF = 1e9;

int n, m;
int x[N], p[N], b[N], idx[N];
ll t[N];

bool cmp(int a, int b) { return x[a] < x[b]; }

ll mx[N<<2];

void push_up(int id) {
    mx[id] = max(mx[id<<1], mx[id<<1^1]);
}

void build(int l, int r, int id) {
    if (l == r) {
        mx[id] = x[idx[l]] + t[idx[l]];
        return;
    }
    int m = l + r >> 1;
    build(l, m, id << 1);
    build(m + 1, r, id << 1 ^ 1);
    push_up(id);
}

void update(int pos, ll val, int l, int r, int id) {
    if (pos < l || pos > r) return;
    if (l == r) {
        mx[id] = val;
        return;
    }
    int m = l + r >> 1;
    update(pos, val, l, m, id << 1);
    update(pos, val, m + 1, r, id << 1 ^ 1);
    push_up(id);
}

int query(ll val, int l, int r, int id) {
    if (l == r) {
        if (mx[id] >= val) return l;
        else return INF;
    }
    int m = l + r >> 1;
    if (mx[id<<1] >= val) return query(val, l, m, id << 1);
    return query(val, m + 1, r, id << 1 ^ 1);
}

multiset<pli> rest;
multiset<pli> :: iterator it;
int cnt[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %I64d", &x[i], &t[i]);
        idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    build(1, n, 1);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &p[i], &b[i]);
        int pos = query(p[i], 1, n, 1);
        rest.insert(pli(p[i], b[i]));
        if (pos == INF || pos != INF && x[idx[pos]] > p[i]) {
            ;
        }
        else {
            ll y = x[idx[pos]] + t[idx[pos]];
            while (!rest.empty()) {
                it = rest.lower_bound(pli(p[i], -1));
                if (it == rest.end()) break;
                if (it -> first > y) break;
                y += it -> second;
                cnt[idx[pos]] ++;
                rest.erase(it);
            }
            update(pos, y, 1, n, 1);
            t[idx[pos]] = y - x[idx[pos]];
        }
    }
    for (int i = 1; i <= n; i ++) printf("%d %I64d\n", cnt[i], t[i]);
    return 0;
}