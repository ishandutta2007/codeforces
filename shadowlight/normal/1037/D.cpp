#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <bool> used;

vector <int> a;

vector <int> cnt;

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
    vector <int> gr[n];
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        sort(gr[i].begin(), gr[i].end());
    }
    vector <bool> used(n, false);
    int s;
    cin >> s;
    s--;
    queue <int> q;
    q.push(s);
    if (s) {
        cout << "No\n";
        return 0;
    }
    while (q.size()) {
        int now = q.front();
        q.pop();
        used[now] = true;
        vector <int> all;
        for (int v : gr[now]) {
            if (used[v]) continue;
            all.push_back(v);
        }
        vector <int> so;
        for (int i = 0; i < (int) all.size(); i++) {
            int x;
            cin >> x;
            x--;
            so.push_back(x);
            q.push(x);
        }
        sort(so.begin(), so.end());
        if (so != all) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}