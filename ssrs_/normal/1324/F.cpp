#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> child(vector<vector<int>> E, int r){
    int N = E.size();
    vector<vector<int>> c(N);
    queue<int> Q;
    Q.push(r);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
            if (c[w].empty()){
                c[v].push_back(w);
                Q.push(w);
            }
        }
    }
    return c;
}
int add(int A, int B){
    return A + B;
}
int root(int A, int a){
    if (a == 0){
        return max(A - 1, 0);
    } else {
        return A + 1;
    }
}
int dfs1(vector<int> &dp, vector<vector<int>> &c, vector<int> &a, int v){
    for (int w : c[v]) dp[v] = add(dp[v], root(dfs1(dp, c, a, w), a[w]));
    return dp[v];
}
void dfs2(vector<int> &dp1, vector<int> &dp2, vector<vector<int>> &c, vector<int> &a, int v){
    int deg = c[v].size();
    vector<int> L(deg + 1, 0), R(deg + 1, 0);
    for (int i = 0; i < deg; i++) L[i + 1] = add(L[i], root(dp1[c[v][i]], a[c[v][i]]));
    for (int i = deg - 1; i >= 0; i--) R[i] = add(R[i + 1], root(dp1[c[v][i]], a[c[v][i]]));
    for (int i = 0; i < deg; i++){
        //cout << "v=" << v << ", w=" << c[v][i] << endl;
        //cout << add(L[i], R[i + 1]) << endl;
        dp2[c[v][i]] = root(add(dp2[v], add(L[i], R[i + 1])), a[v]);
        dfs2(dp1, dp2, c, a, c[v][i]);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<vector<int>> c = child(E, 0);
    vector<int> dp1(n, 0), dp2(n, 0);
    dfs1(dp1, c, a, 0);
    dfs2(dp1, dp2, c, a, 0);
    for (int i = 0; i < n; i++){
        cout << add(dp1[i], dp2[i]) + (a[i] == 1 ? 1 : -1) << endl;
    }
}