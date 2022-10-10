#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1505;
int n, q, gr[MAXN][MAXN], sw[MAXN], seen[MAXN*MAXN];
vector<pair<int, int>> v[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> gr[i][j];

    for(int r = n; r >= 1; r--) {
        for(int c = n; c >= 1; c--) {
            vector<pair<int, int>> guys, pm;
            guys.push_back({1, gr[r][c]});

            for(auto &[t, co] : v[r + 1][c])
                guys.push_back({t + 1, co});

            for(auto &[t, co] : v[r + 1][c + 1]) 
                guys.push_back({t + 1, co});

            for(auto &[t, co] : v[r][c + 1])
                guys.push_back({t + 1, co});

            sort(guys.begin(), guys.end());
            for(auto &[t, co] : guys) {
                if(seen[co]) continue;
                if(t > n + 1 - max(r, c))
                    break;
                seen[co] = 1;
                pm.push_back({t, co});
                if(pm.size() == q + 1)
                    break;
            }
            for(auto &[t, co] : guys)
                seen[co] = 0;
            v[r][c] = pm;
            if(v[r][c].size() == q + 1)
                sw[min(n + 1 - max(r, c), v[r][c].back().first - 1)]++;
            else
                sw[n + 1 - max(r, c)]++;
            if(c == 1) {
                for(int i = 1; i <= n; i++) {
                    v[r + 1][i].clear();
                    v[r + 1][i].shrink_to_fit();
                }
            }
        }
    }

    for(int i = n; i >= 1; i--)
        sw[i] += sw[i + 1];

    for(int i = 1; i <= n; i++)
        cout << sw[i] << '\n';
}