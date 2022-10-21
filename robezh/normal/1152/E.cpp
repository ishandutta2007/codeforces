#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n, m;
int a[N], b[N], c[N];

vector<int> res;
multiset<int> G[N];


void dfs(int v){
    //cout << "finding "  << (char)(v / 128) << (char)(v % 128) << endl;
    while(G[v].size()){
        int nxt = *G[v].begin();
        G[nxt].erase(G[nxt].find(v));
        G[v].erase(G[v].begin());
        dfs(nxt);
    }
    res.push_back(v);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> b[i], a[i] = b[i];
    for(int i = 0; i < n - 1; i++) cin >> c[i], a[i + (n - 1)] = c[i];
    for(int i = 0; i < n - 1; i++) {
        if(b[i] > c[i]) return cout << -1 << endl, 0;
    }
    m = 2 * (n - 1);
    sort(a, a + m);
    m = (int)(unique(a, a + m) - a);
    for(int i = 0; i < n - 1; i++) {
        int u = (int)(lower_bound(a, a + m, b[i]) - a);
        int v = (int)(lower_bound(a, a + m, c[i]) - a);
        G[u].insert(v);
        G[v].insert(u);
    }
    int odd = 0, odd_i = -1;
    for(int i = 0; i < m; i++) {
        if(G[i].size() % 2 == 1) {
            odd++;
            odd_i = i;
        }
    }
//    cout << "?" << endl;
//    cout << odd << endl;
    if(odd > 2) return cout << -1 << endl, 0;
    if(odd_i == -1) odd_i = 0;
    dfs(odd_i);
//    cout << G[0].size() << endl;
//    cout << m << endl;

    for(int i = 0; i < m; i++) if(!G[i].empty()) return cout << -1 << endl, 0;
    for(int i = 0; i < n; i++) cout << a[res[i]] << " ";
    cout << endl;
}