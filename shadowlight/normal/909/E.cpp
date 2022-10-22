#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;
vector <int> cnt;

int n, m;
vector <int> t;

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
    cin >> n >> m;
    gr.resize(n);
    t.resize(n);
    cnt.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        gr[u].push_back(v);
        cnt[v]++;
    }
    queue <int> now, q;
    for (int i = 0; i < n; i++) {
        if (cnt[i]) continue;
        if (t[i]) {
            q.push(i);
        } else {
            now.push(i);
        }
    }
    while (!now.empty()) {
        int v = now.front();
        now.pop();
        for (int u : gr[v]) {
            cnt[u]--;
            if (!cnt[u]) {
                if (t[u]) {
                    q.push(u);
                } else {
                    now.push(u);
                }
            }
        }
    }
    int res = 0;
    while (!q.empty()) {
        res++;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : gr[v]) {
                cnt[u]--;
                if (!cnt[u]) {
                    if (t[u]) {
                        q.push(u);
                    } else {
                        now.push(u);
                    }
                }
            }
        }
        while (!now.empty()) {
            int v = now.front();
            now.pop();
            for (int u : gr[v]) {
                cnt[u]--;
                if (!cnt[u]) {
                    if (t[u]) {
                        q.push(u);
                    } else {
                        now.push(u);
                    }
                }
            }
        }
    }
    cout << res;
}