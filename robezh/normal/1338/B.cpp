#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what(x) cerr << #x << " is " << x << endl;

const int N = (int)1e5 + 50;

int n, root;
vi G[N];
int sub[N];
int res = n - 1;
bool has_odd = false;

void dfs(int v, int p, int d) {
    sub[v] = 1;
    int cnt = 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v, d + 1);
        sub[v] += sub[nxt];
        cnt += (sub[nxt] == 1);
    }
    cnt += (p == root);
    if(sub[v] == 1 && d % 2 == 1) has_odd = true;
    res -= max(0, cnt - 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n == 3) {
        cout << "1 1\n";
        return 0;
    }
    root = -1;
    for(int i = 0; i < n; i++) {
        if(G[i].size() == 1) root = i;
    }
    res = n - 1;
    dfs(root, -1, 0);

    cout << (has_odd ? 3 : 1) << " " << res << endl;

}