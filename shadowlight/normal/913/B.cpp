#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;

void dfs(int v) {
    int cnt = 0;
    for (int u : gr[v]) {
        if (!gr[u].size()) {
            cnt++;
        } else {
            dfs(u);
        }
    }
    if (cnt < 3) {
        cout << "No\n";
        exit(0);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int v;
        cin >> v;
        v--;
        gr[v].push_back(i);
    }
    dfs(0);
    cout << "Yes\n";
}