#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n, m;
    cin >> n >> m;
    int sz;
    cin >> sz;
    vector <int> a(sz);
    for (int &x : a) {
        cin >> x;
        x--;
    }
    vector <bool> banned(m, false), need(m, false);
    vector <vector <int> > block(m);
    for (int i = 1; i < n; i++) {
        int sz;
        cin >> sz;
        vector <int> b(sz);
        for (int &x : b) {
            cin >> x;
            x--;
        }
        bool fl = false;
        for (int j = 0; j < min(a.size(), b.size()); j++) {
            if (a[j] != b[j]) {
                fl = true;
                if (a[j] > b[j]) {
                    banned[b[j]] = true;
                    need[a[j]] = true;
                    //cout << "1 " << b[j] << " " << a[j] << "\n";
                } else {
                    block[b[j]].push_back(a[j]);
                    //cout << "2 " << b[j] << " " << a[j] << "\n";
                }
                break;
            }
        }
        if (!fl) {
            //cout << "0\n";
            if (a.size() > b.size()) {
                cout << "No\n";
                return 0;
            }
        }
        a = b;
    }
    queue <int> q;
    for (int i = 0; i < m; i++) {
        if (banned[i] && need[i]) {
            cout << "No\n";
            return 0;
        } else if (need[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : block[v]) {
            if (need[u]) continue;
            if (banned[u]) {
                cout << "No\n";
                return 0;
            }
            need[u] = true;
            q.push(u);
        }
    }
    cout << "Yes\n";
    vector <int> res;
    for (int i = 0; i < m; i++) {
        if (need[i]) {
            res.push_back(i + 1);
        }
    }
    cout << res.size() << "\n";
    for (int x : res) {
        cout << x << " ";
    }
}