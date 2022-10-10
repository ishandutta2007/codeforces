#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m), guys(n + 1);
    vector<int> ass(m), alone(n + 1);

    for(int i = 0; i < m; i++) {
        int f;
        cin >> f;
        for(int j = 0; j < f; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
            guys[x].push_back(i);
        }
        if(f == 1)
            alone[v[i][0]]++;
    }

    int ta = (m + 1)/2;
    for(int i = 1; i <= n; i++) {
        if(alone[i] > ta) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        if(guys[i].size() >= ta) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(v[j].size() == 1) {
                    ass[j] = v[j][0];
                    if(v[j][0] == i)
                        cnt++;
                }
            }
            for(int j = 0; j < guys[i].size(); j++) {
                if(cnt == ta || ass[guys[i][j]])
                    continue;
                ass[guys[i][j]] = i;
                cnt++;
            }
            for(int j = 0; j < m; j++) {
                if(!ass[j]) {
                    if(v[j][0] != i)
                        ass[j] = v[j][0];
                    else
                        ass[j] = v[j][1];

                }
            }
            for(int j = 0; j < m; j++)
                cout << ass[j] << " ";
            cout << '\n';
            return;
        }
    }

    for(int j = 0; j < m; j++)
        cout << v[j][0] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}