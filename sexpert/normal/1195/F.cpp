#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
map<ii, int> lst;
 
const int MAXN = 3e5 + 10;
int BIT[MAXN], prv[MAXN], fin[MAXN], ans[MAXN];
ii slp[MAXN];
 
void upd(int p, int v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v;
}
 
int sum(int p) {
    int res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}
 
struct qry {
    int l, r, idx;
};
 
vector<qry> qs[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, cur = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        vector<ii> v(k);
        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            v[j] = {x, y};
        }
        for(int j = 0; j < k; j++) {
            int dx = v[(j + 1)%k].first - v[j].first, dy = v[(j + 1)%k].second - v[j].second;
            int g = __gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            slp[cur + j + 1] = {dx, dy};
        }
        cur += k;
        fin[i] = cur;
    }
    //for(int i = 1; i <= cur; i++)
    //    cout << "{" << slp[i].first << ", " << slp[i].second << "}\n";
 
 
    for(int i = 1; i <= cur; i++) {
        if(!lst.count(slp[i]))
            prv[i] = 0;
        else
            prv[i] = lst[slp[i]];
        lst[slp[i]] = i;
    }
 
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r;
        l = fin[l - 1] + 1;
        r = fin[r];
        qs[r].push_back({l, r, i + 1});
    }
    for(int r = 1; r <= cur; r++) {
        upd(r, 1);
        if(prv[r] > 0)
            upd(prv[r], -1);
        for(auto q : qs[r]) {
            int to = sum(r) - sum(q.l - 1);
            ans[q.idx] = to;
        }
    }
    for(int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}