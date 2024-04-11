#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

const int N = (int)2e5 + 50;
const int INF = (int)1e9;
typedef long long ll;

int n,m;
int a[N];

struct P {
    int l, r, c;
} p[N];

map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        cin >> p[i].l >> p[i].r >> p[i].c;
        sum += p[i].c;
        p[i].l--, p[i].r--;
    }
    sort(p, p + m, [](const P &p1, const P &p2) {
        return p1.r < p2.r;
    });
    for(int i = 0; i < n; i++) mp[i] = a[i];
    for(int i = 0; i < m; i++) {
        auto it = mp.lower_bound(p[i].l);
        while(it != mp.end() && it->first <= p[i].r) {
            int curj = it->first;
            int tk = min(it->second, p[i].c);
            p[i].c -= tk;
            mp[curj] -= tk;
            sum -= tk;
            if(mp[curj] == 0) it = mp.erase(it);
            else break;
        }
    }
    cout << sum << endl;

}