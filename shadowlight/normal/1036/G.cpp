#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, m;
vector <vector <int> > gr;
vector <int> st, num, mask;

void dfs(int v) {
    if (mask[v] != -1) return;
    if (!gr[v].size()) {
        mask[v] = (1 << (int) num[v]);
        return;
    }
    mask[v] = 0;
    for (int u : gr[v]) {
        dfs(u);
        mask[v] |= mask[u];
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m;
    gr.resize(n);
    st.resize(n, 0);
    mask.resize(n, -1);
    num.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        st[u]++;
    }
    vector <int> ts;
    for (int i = 0; i < n; i++) {
        if (!gr[i].size()) {
            ts.push_back(i);
            num[i] = ts.size() - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    vector <int> s;
    for (int i = 0; i < n; i++) {
        if (!st[i]) {
            s.push_back(i);
        }
    }
    assert(s.size() == ts.size());
    for (int i = 1; i < (1 << (int) s.size()) - 1; i++) {
        int now = 0;
        for (int j = 0; j < s.size(); j++) {
            if (i & (1 << j)) {
                now |= mask[s[j]];
            }
        }
        //cout << now << " " << i << "\n";
        if (__builtin_popcount(now) <= __builtin_popcount(i)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}