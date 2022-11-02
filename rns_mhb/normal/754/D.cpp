#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree <pii, null_type, greater <pii>, rb_tree_tag, tree_order_statistics_node_update> order_set;

#define N 300005

int n, k, cnt;
int l[N], r[N], gas[N*2];
int z[N*2];
int vis[N];

int ansl, ansr, mx;

vector<int> v[N*2];
order_set s;
order_set :: reverse_iterator rit;
order_set :: iterator it;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%d %d", &l[i], &r[i]);
        z[cnt++] = l[i], z[cnt++] = r[i];
    }
    sort(z, z + cnt);
    int m = unique(z, z + cnt) - z;
    for (int i = 0; i < n; i ++) {
        l[i] = lower_bound(z, z + m, l[i]) - z;
        r[i] = lower_bound(z, z + m, r[i]) - z;
        v[l[i]].push_back(r[i]);
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            int x = v[i][j];
            s.insert(pii(x, ++gas[x]));
        }
        if (s.size() >= k) {
            it = s.find_by_order(k - 1);
            int st = it -> first;
            if (mx < z[st] - z[i] + 1) {
                mx = z[st] - z[i] + 1;
                ansl = i, ansr = st;
            }
        }
        while (!s.empty()) {
            rit = s.rbegin();
            if (rit -> first == i) {
                s.erase(rit);
            }
            else break;
        }
    }
    if (!mx) {
        printf("0\n");
        for (int i = 1; i <= k; i ++) printf("%d ", i);
        return 0;
    }
    printf("%d\n", mx);
    int j = 0;
    for (int i = 0; i < n && j < k; i ++) {
        if (l[i] <= ansl && ansr <= r[i]) {
            printf("%d ", i + 1);
            j ++;
        }
    }
    return 0;
}