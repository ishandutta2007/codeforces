#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e5 + 50;

int n;
int num[N];
vector<vector<int> > cyc[N];
bool vis[N];
int to[N];
vector<int> S;
vector<P> res;

void dfs(int x) {
    vis[x] = true;
    S.push_back(x);
    if(!vis[num[x]]) dfs(num[x]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i], num[i]--;

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        S.clear();
        dfs(i);
        cyc[S.size()].push_back(S);
    }
    if(cyc[1].empty() && cyc[2].empty()) return cout << "NO" << endl, 0;
    memset(to, -1, sizeof(to));
    for(int i = 1; i <= n; i++) {
        if(cyc[i].empty()) continue;
        if(i != 1 && i != 2 && to[i] == -1) return cout << "NO" << endl, 0;
        for(int j = i * 2; j <= n; j += i) to[j] = i;
    }
    int root = cyc[1].empty() ? 2 : 1;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < cyc[i].size(); j++) {
            if(i == root && j == 0) {
                if(root == 2) res.push_back({cyc[i][j][0], cyc[i][j][1]});
                continue;
            }
            if(j == 0) {
                for(int k = 0; k < i; k++) {
                    res.push_back({cyc[i][j][k], cyc[to[i]][0][k % to[i]]});
                }
            }
            else {
                for(int k = 0; k < i; k++) {
                    res.push_back({cyc[i][j][k], cyc[i][0][k]});
                }
            }
        }
    }
    cout << "YES" << endl;
    for(const auto &p : res) cout << p.first + 1 << " " << p.second + 1 << "\n";
}