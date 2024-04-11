#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ii = array<int, 2>;

const int MAXN = 1e4 + 10;
vector<int> rep1(510), rep2;
int ans[3*MAXN];
vector<ii> ed;
vector<ii> used[MAXN];
vector<array<int, 3>> qs;

int find(int u, vector<int> &rep) {
    return rep[u] == u ? u : rep[u] = find(rep[u], rep);
}

bool join(int u, int v, vector<int> &rep) {
    u = find(u, rep), v = find(v, rep);
    if(u == v)
        return false;
    rep[v] = u;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ed.resize(m);
    for(auto &[u, v] : ed)
        cin >> u >> v;
    iota(rep1.begin(), rep1.end(), 0);
    for(int i = 1; i <= m; i++) {
        used[i] = used[i - 1];
        if(join(ed[i - 1][0], ed[i - 1][1], rep1)) {
            used[i].push_back({ed[i - 1][0], ed[i - 1][1]});
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qs.push_back({l, r, i});
    }
    sort(qs.begin(), qs.end(), [&](array<int, 3> a, array<int, 3> b){ return a[1] > b[1]; });
    iota(rep1.begin(), rep1.end(), 0);
    int lst = m;
    int gloc = n;
    for(auto& [L, R, idx] : qs) {
        //cout << L << " " << R << " " << idx << endl;
        while(lst > R) {
            lst--;
            if(join(ed[lst][0], ed[lst][1], rep1))
                gloc--;
        }
        //cout << gloc << endl;
        rep2 = rep1;
        int res = gloc;
        for(auto& [u, v] : used[L - 1]) {
            if(join(u, v, rep2))
                res--;
        }
        //cout << idx << " " << res << endl;
        ans[idx] = res;
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;

    //cout << "FINISHED" << endl;
    return 0;
}