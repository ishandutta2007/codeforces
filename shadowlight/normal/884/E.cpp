#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int cnt = 0;

struct Dsu {
    int n;
    vector <int> p, r;
    Dsu(int n) : n(n) {
        p.resize(n, -1);
        r.resize(n, 0);
    }
    int get(int v) {
        if (p[v] == v || p[v] == -1) return p[v];
        return p[v] = get(p[v]);
    }
    void uni(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == -1 || u == -1) return;
        if (v == u) return;
        if (r[v] == r[u]) r[u]++;
        if (r[v] > r[u]) {
            swap(v, u);
        }
        p[v] = u;
        cnt--;
    }
};

int toI(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return c - '0';
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
    int n, m;
    cin >> n >> m;
    Dsu pred(m);
    for (int i = 0; i < n; i++) {
        Dsu now(m);
        for (int j = 0; j < m; j += 4) {
            char x;
            cin >> x;
            int k = toI(x);
            for (int c = 3; c >= 0; c--) {
                if (k % 2) {
                    now.p[j + c] = j + c;
                    cnt++;
                }
                k /= 2;
            }
        }
        //cout << "kek\n";
        for (int i = 1; i < m; i++) {
            now.uni(i - 1, i);
        }
        vector <int> pr(m, -1);
        for (int i = 0; i < m; i++) {
            if (pred.p[i] == -1 || now.p[i] == -1) continue;
            if (pr[pred.get(i)] == -1) {
                pr[pred.get(i)] = now.get(i);
                cnt--;
            } else {
                now.uni(pr[pred.get(i)], i);
            }
        }
        pred = now;
    }
    cout << cnt;
}