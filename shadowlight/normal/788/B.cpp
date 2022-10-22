#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

vector <vector <int> > gr;
vector <int> used;

void dfs(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (int u : gr[v]) {
        dfs(u);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //  freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    used.resize(n, 0);
    gr.resize(n);
    vector <int> eloop(n, 0);
    ll loop = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            loop++;
            eloop[l] = 1;
            continue;
        }
        gr[l].push_back(r);
        gr[r].push_back(l);
    }
    for (int i = 0; i < n; i++) {
        if (eloop[i] || gr[i].size()) {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i] && (gr[i].size() || eloop[i])) {
            cout << 0;
            return 0;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll x = gr[i].size();
        //cout << x << " ";
        cnt += x * (x - 1) / 2LL;
    }
    //cout << endl;
    //cout << loop << " " << m - loop << endl;
    cnt += loop * (m - 1);
    cnt -= loop * (loop - 1) / 2;
    cout << cnt;
}