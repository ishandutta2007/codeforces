#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;
int n, m, v1, v2;
vector <pair<int, int> > b;
vector <int> a, v, es[N];
bool u[N];
vector <vector<int> > ans;

void dfs(int w) {
    if (u[w])
        return;
    u[w] = true;
    v.push_back(w + 1);
    for (int i = 0; i < es[w].size(); i++)
        dfs(es[w][i]);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++)
        if (!u[i]) {
            v.clear();
            dfs(i);
            if (v.size() > 3) {
                cout << -1;
                return 0;
            }
            if (v.size() == 3) 
                ans.push_back(v);
            if (v.size() == 2)
                b.push_back(make_pair(v[0], v[1]));
            if (v.size() == 1)
                a.push_back(v[0]);
        }

    if (b.size() > a.size()) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 3; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    
    while (a.size() > b.size()) {
        cout << a.back() << " ";
        a.pop_back();
        cout << a.back() << " ";
        a.pop_back();
        cout << a.back() << "\n";
        a.pop_back();
    }

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " " << b[i].first << " " << b[i].second << "\n";
    }

    return 0;
}