#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9 + 5;

int n;
int val[N], l[N], r[N];
bool good[N];
int in_deg[N];
int root;
map<int, int> mp;

void dfs(int v, int lb, int rb) {
    if(lb <= val[v] && val[v] <= rb && mp[val[v]] == 0) {
        good[v] = true;
    }
    mp[val[v]]++;
    if(l[v] != -1) dfs(l[v], lb, min(rb, val[v] - 1));
    if(r[v] != -1) dfs(r[v], max(lb, val[v] + 1), rb);
    mp[val[v]]--;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> val[i] >> l[i] >> r[i];
        if(l[i] != -1) in_deg[l[i]]++;
        if(r[i] != -1) in_deg[r[i]]++;
    }
    for(int i = 1; i <= n; i++) if(in_deg[i] == 0) root = i;
    dfs(root, -1, INF);
    int res = 0;
    for(int i = 1; i <= n; i++) if(good[i]) mp[val[i]] ++;
    for(int i = 1; i <= n; i++) res += (mp[val[i]] == 0);
    cout << res << endl;
}