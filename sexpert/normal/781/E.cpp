#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 2e9;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
map<int, int> le, ri, ss;
map<ii, int> down, dp;
int h, w, n;
vector<int> barpos, col[MAX];

struct node {
    int l, r, val;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l)
            return;
        if(l == r)
            { val = v; return; }
        left->upd(p, v);
        right->upd(p, v);
        val = min(left->val, right->val);
    }

    int search(int rl, int rr, int t) {
        //cout << "search <= " << t << " in [" << rl << ", " << rr << "] currently in [" << l << ", " << r << "]" << endl;
        if(val > t)
            return -1;
        if(r < rl || rr < l)
            return -1;
        if(l == r) {
            //cout << "did it! found " << val << " at " << l << endl;
            return l;
        }
        int s = left->search(rl, rr, t);
        if(s != -1)
            return s;
        return right->search(rl, rr, t);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n;
    for(int i = 0; i < n; i++) {
        int u, l, r, s;
        cin >> u >> l >> r >> s;
        le[u] = l;
        ri[u] = r;
        ss[u] = s;
        barpos.push_back(u);
    }
    le[0] = 1;
    ri[0] = w;
    ss[0] = h + 5;
    barpos.push_back(0);
    node tree(1, w);
    sort(barpos.rbegin(), barpos.rend());
    for(int i = 1; i <= w; i++) {
        tree.upd(i, h + 1);
        col[i].push_back(h + 1);
    }
    for(auto he : barpos) {
        int l = le[he], r = ri[he], s = ss[he];
        //cout << "Bar at height " << he << ": " << l << ", " << r << " scared up of " << he + s << endl;
        while(true) {
            int x = tree.search(l, r, he + s);
            if(x == -1)
                break;
            //cout << "found candidate in column " << x  << " " << col[x].back() << endl;
            while(!col[x].empty() && col[x].back() <= he + s) {
                int z = col[x].back(); col[x].pop_back();
                down[{z, x}] = he;
            }
            if(col[x].empty())
                tree.upd(x, INF);
            else
                tree.upd(x, col[x].back());
        }
        if(l - 1 >= 1) {
            tree.upd(l - 1, he);
            col[l - 1].push_back(he);
        }
        if(r + 1 <= w) {
            tree.upd(r + 1, he);
            col[r + 1].push_back(he);
        }
    }
    int ans = 0;
    for(auto p : down) {
        auto pos = p.first;
        int to = p.second;
        if(to == 0)
            dp[pos] = 1;
        else {
            int l = le[to] - 1, r = ri[to] + 1;
            if(l == 0) {
                dp[pos] = 2*dp[{to, r}];
                if(dp[pos] >= MOD)
                    dp[pos] -= MOD;
            }
            else if(r == w + 1) {
                dp[pos] = 2*dp[{to, l}];
                if(dp[pos] >= MOD)
                    dp[pos] -= MOD;
            }
            else {
                dp[pos] = dp[{to, l}] + dp[{to, r}];
                if(dp[pos] >= MOD)
                    dp[pos] -= MOD;
            }
        }
        //cout << pos.first << ", " << pos.second << " -> " << p.second << " " << dp[pos] << endl;
        if(pos.first == h + 1) {
            ans += dp[pos];
            if(ans >= MOD)
                ans -= MOD;
        }
    }
    cout << ans << '\n';
}