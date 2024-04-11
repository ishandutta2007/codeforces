#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
int dfs(int v, int s, vector<int> &to, vector<int> &seen){
    if(v == -1)
        return 0;
    seen[v] = 1;
    if(v == s)
        return 1;
    return dfs(to[v], s, to, seen);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> to(n, -1);
    vector<int> seen(n, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        to[x] = y;
    }
    int res = m;
    for (int i = 0; i < n; ++i) {
        if(to[i] == i)
            res--;
        else if(!seen[i])
            res += dfs(to[i], i, to, seen);
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}