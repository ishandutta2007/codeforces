#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, m;
int cnt[N];
vector<int> G[N];
ll cur_res = 0;

ll get(int v) {
    return 1LL * G[v].size() * (cnt[v] - G[v].size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--, b--;
        if(a > b) swap(a, b);
        cnt[a]++, cnt[b]++;
        G[a].push_back(b) ;
    }
    for(int i = 0; i < n; i++) cur_res += get(i);
    cout << cur_res << "\n";
    int q;
    cin >> q;
    while(q--) {
        int v; cin >> v; v--;
        cur_res -= get(v);
        for(int x : G[v]) cur_res -= get(x);
        for(int x : G[v]) {
            G[x].push_back(v);
            cur_res += get(x);
        }
        G[v].clear();
        cout << cur_res << "\n";
    }

}