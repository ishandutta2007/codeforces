#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define N 200010

int x[N], y[N], tmp[N];
vector <int> v[N];

long long func(int x) {
    return 1ll * x * (x+1) / 2;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
    for(int i = 1; i <= n; i ++) tmp[i] = x[i];
    sort(tmp + 1, tmp + n + 1);
    int nx = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for(int i = 1; i <= n; i ++) x[i] = lower_bound(tmp + 1, tmp + nx + 1, x[i]) - tmp;
    for(int i = 1; i <= n; i ++) tmp[i] = y[i];
    sort(tmp + 1, tmp + n + 1);
    int ny = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for(int i = 1; i <= n; i ++) y[i] = lower_bound(tmp + 1, tmp + ny + 1, y[i]) - tmp;
    for(int i = 1; i <= n; i ++) v[y[i]].push_back(x[i]);
    order_set s;
    long long ans = 0;
    for(int i = ny; i; i --) {
        if(v[i].empty()) continue;
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); j ++) s.insert(v[i][j]);
        long long cur = func(s.size());
        for(int j = 0; j <= v[i].size(); j ++) {
            int l, r;
            if(j == 0) l = 1, r = v[i][0] - 1;
            else if(j == v[i].size()) l = v[i].back() + 1, r = nx;
            else l = v[i][j-1]+1, r = v[i][j]-1;
            if(l > r) continue;
            int g = s.order_of_key(r+1) - s.order_of_key(l);
            cur -= func(g);
        }
        ans += cur;
    }
    cout << ans << endl;
}