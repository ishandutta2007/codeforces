#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, k;
const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int deg[MAXN], finish[MAXN], killed = 0;
vector<int> leaves;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if(n <= 3) {
        cout << "No\n";
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            leaves.push_back(i);
            finish[i] = 1;
        }
    }

    for(int i = 0; i < k; i++) {
        if(leaves.size() < 3) {
            cout << "No\n";
            return 0;
        }
        //for(auto l : leaves)
        //    cout << l << " ";
        //cout << endl;
        map<int, int> used;
        vector<int> tmp;
        for(auto u : leaves) {
            for(auto v : adj[u]) {
                if(finish[v] && !used.count(v))
                    continue;
                used[v]++;
                deg[v]--;
                //cout << u << " === " << v << endl;
                if(deg[v] == 1) {
                    tmp.push_back(v);
                    finish[v] = 1;
                }
            }
        }
        for(auto p : used) {
            int v = p.first, sons = p.second;
            //cout << v << " " << sons << endl;
            if(sons < 3) {
                cout << "No\n";
                return 0;
            }
            if(!finish[v]) {
                cout << "No\n";
                return 0;
            }
        }
        leaves = tmp;
    }

    if(leaves.size() != 1) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
}