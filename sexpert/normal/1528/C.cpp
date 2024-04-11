#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 3e5 + 10;
vector<int> adj1[MAXN], adj2[MAXN];
int tin[MAXN], tout[MAXN], curt, ans;
set<ii> cur;

void dfs2(int s) {
    tin[s] = ++curt;
    for(auto v : adj2[s])
        dfs2(v);
    tout[s] = curt;
}

void dfs(int s) {
    //cout << "vertex " << s << endl;
    array<ii, 2> adrem = {ii{-1, -1}, ii{-1, -1}};
    if(cur.empty()) {
        //cout << "added [" << tin[s] << ", " << tout[s] << "]" << endl;
        cur.insert({tin[s], tout[s]});
        adrem = {ii{tin[s], tout[s]}, ii{-1, -1}};
    }
    else {
        bool add = true;
        auto it = cur.lower_bound({tin[s], 0});
        if(it != cur.end() && (*it)[0] >= tin[s] && (*it)[1] <= tout[s])
            add = false;
        if(add) {
            //cout << "added [" << tin[s] << ", " << tout[s] << "]" << endl;
            adrem[0] = {tin[s], tout[s]};
            auto it = cur.lower_bound({tout[s], 0});
            if(it != cur.begin()) {
                --it;
                if((*it)[0] <= tin[s] && tout[s] <= (*it)[1]) {
                    //cout << "erased [" << (*it)[0] << ", " << (*it)[1] << "]" << endl;
                    adrem[1] = {(*it)[0], (*it)[1]};
                    cur.erase(adrem[1]);
                }
            }
            cur.insert(adrem[0]);
        }
    }
    ans = max(ans, (int)cur.size());
    for(auto v : adj1[s])
        dfs(v);
    if(adrem[0][0] != -1) {
        //cout << "erased [" << adrem[0][0] << ", " << adrem[0][1] << "]" << endl;
        cur.erase(adrem[0]);
    }
    if(adrem[1][0] != -1) {
        //cout << "added [" << adrem[1][0] << ", " << adrem[1][1] << "]" << endl;
        cur.insert(adrem[1]);
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        adj1[i].clear();
        adj2[i].clear();
    }
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj1[p].push_back(i);
    }
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj2[p].push_back(i);
    }

    curt = 0;
    dfs2(1);
    //for(int i = 1; i <= n; i++)
    //    cout << tin[i] << " " << tout[i] << endl;
    ans = 0;
    dfs(1);
    assert(cur.size() == 0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}