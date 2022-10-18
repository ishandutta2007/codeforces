#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 10;
int all[N], cnt, n;
struct node {
    int l, r, id;
};
vector<node> p[N];
#define ls x << 1
#define rs x << 1 | 1
ll sum[N << 2], tag[N << 2];

void build(int x, int l, int r) {
    if(l == r) {
        sum[x] = tag[x] = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    sum[x] = tag[x] = 0;
    build(ls, l, mid), build(rs, mid + 1, r);
}

void down(int x, int l, int r) {
    int mid = (l + r) >> 1;
    if(tag[x]) {
        tag[ls] += tag[x];
        sum[ls] += tag[x] * (mid - l + 1);
        tag[rs] += tag[x];
        sum[rs] += tag[x] * (r - mid);
        tag[x] = 0;
    }
}

void upd(int x, int l, int r, int L, int R, int k) {
    if(L <= l && r <= R) {
        sum[x] += 1ll * k * (r - l + 1);
        tag[x] += k;
        return ;
    }
    down(x, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(ls, l, mid, L, R, k);
    if(R > mid) upd(rs, mid + 1, r, L, R, k);
    sum[x] = sum[ls] + sum[rs];
}

ll get(int x, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sum[x];
    }
    down(x, l, r);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if(L <= mid) ans += get(ls, l, mid, L, R);
    if(R > mid) ans += get(rs, mid + 1, r, L, R);
    return ans;
}

void chg(int col,  int k) {
    for(auto [x, y, z] : p[col]) {
        upd(1, 1, cnt, x, y, k);
    }
}

int find(int be, int ed) {
    // cout << be << " " << ed << " " << get(1, 1, cnt, be, ed) << endl;
    int l = 0, r = cnt - ed, ans = 1e9;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(get(1, 1, cnt, be, ed + mid)) {
            // if(all[ed + mid] == all[ed]) cout << mid << "??\n";
            r = mid - 1, ans = min(ans, all[ed + mid] - all[ed]);
        }else l = mid + 1;
    }
    l = 0, r = be - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(get(1, 1, cnt, be - mid, ed)) {
            // if(all[be] == all[be - mid]) cout << mid << "?\n";
            r = mid - 1, ans = min(ans, all[be] - all[be - mid]);
        } else l = mid + 1;
    }
    // cout << ans << endl;
    return ans;
}

void solve() {
    cnt = 0;
    cin >> n;
    vector<int> da(n);
    for(int i = 1; i <= n; ++i) p[i].clear();
    for(int i = 1, x, y, z; i <= n; ++i) {
        cin >> x >> y >> z;
        p[z].push_back({x, y, i - 1});
        all[++cnt] = x, all[++cnt] = y;
    }
    sort(all + 1, all + 1 + cnt);
    cnt = unique(all + 1, all + 1 + cnt) - all - 1;
    build(1, 1, cnt);
    for(int i = 1; i <= n; ++i)
        for(auto& [x, y, z] : p[i]) {
            x = lower_bound(all + 1, all + 1 + cnt, x) - all;
            y = lower_bound(all + 1, all + 1 + cnt, y) - all;
            // cout << x << " " << y << endl;
            upd(1, 1, cnt, x, y, 1);
        }
    for(int i = 1; i <= n; ++i) {
        chg(i, -1);
        for(auto [x, y, id] : p[i]) {
            // cout << id << "\n";
            da[id] = find(x, y);
        }
        chg(i, 1);
    }
    for(auto x : da) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
    return 0;
}//