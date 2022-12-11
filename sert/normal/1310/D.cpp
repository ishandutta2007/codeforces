#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
 
const int INF = (int)1e9 + 41;
 
vector<vector<vector<pair<int, int>>>> min2;

int u[100];
int uu = 34;
int ans = 0;
int L;
 
void check(const vector<int> &pth) {
    uu++;
    for (int x : pth) u[x] = uu;
    u[0] = uu;
 
    int cur = 0;
 
    for (int i = 0; i <= L; i++) {
        int v1 = (i == 0 ? 0 : pth[i - 1]);
        int v2 = (i == L ? 0 : pth[i]);
 
        int w = -1; 
        const auto &m2 = min2[v1][v2];
        for (int j = 0; w == -1 && j < (int)m2.size(); j++) {
            if (u[m2[j].second] != uu) {
                w = m2[j].first;
            }
        }

        if (w == -1) cur = INF;
        cur += w;
    }
    if (cur < ans) {
        ans = cur;
        //for (int x : path) cout << x;
        //cout << "\n";
    }    
}
 
void gen(vector<int> &a, int len, int n) {
    if (len == 0) {
        check(a);
        return;
    }
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        a.back() = i;
        gen(a, len - 1, n);
    }
    a.pop_back();
}
 
void solve() {
    /*vector<int> v = {1, 1, 0, 0};
    while (true) {
        for (int x : v) cout << x;
            cout << "\n";
        if (!prev_permutation(v.begin(), v.end())) break;
    }
    return;*/
 
    int n, k;
    cin >> n >> k;
    
    min2.resize(n);
    for (int i = 0; i < n; i++) min2[i].resize(n);
 
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
 
    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = 0; v2 < n; v2++) {
            for (int x = 0; x < n; x++) {
                min2[v1][v2].emplace_back(dist[v1][x] + dist[x][v2], x);
            }
            sort(min2[v1][v2].begin(), min2[v1][v2].end());
        }
    }    
 
    ans = INF;
    vector<int> items;
    L = k / 2 - 1;
    gen(items, L, n);
 
    cout << ans << "\n";
}
 
int main() {
    solve();
}