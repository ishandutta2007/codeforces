#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 3500 + 7;

ll a[N], b[N][N];
ll n, m, t, k;
ll d[N][N];
ll s1, f1, l1, s2, f2, l2, ans = 100500, kol, ta;
ll t0, t1, t2, v1, v2;
vector <int> es[N];

void bfs(int st) {
    queue <int> q;
    int w, v;
    while (!q.empty()) q.pop();
    q.push(st);
    d[st][st] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < es[v].size(); i++) {
            w = es[v][i];
            if (d[st][w] == -1) {
                d[st][w] = d[st][v] + 1;
                q.push(w);
            }
        }
    }
}

int main() {
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        kol++;
    }

    cin >> s1 >> f1 >> l1 >> s2 >> f2 >> l2;
    s1--; f1--; s2--; f2--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = -1;

    for (int i = 0; i < n; i++)
        bfs(i);

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cerr << d[i][j] << " ";
        cerr << "\n";
    }*/

    if (d[s1][f1] <= l1 && d[s2][f2] <= l2)
        ans = d[s1][f1] + d[s2][f2];


    for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
        t0 = d[i][j];
        t1 = min(d[i][s1] + d[j][f1], d[i][f1] + d[j][s1]);
        t2 = min(d[i][s2] + d[j][f2], d[i][f2] + d[j][s2]);
        if (t0 + t1 <= l1 && t0 + t2 <= l2) {
            ans = min(ans, t0 + t1 + t2);
        }
    }

    if (ans == 100500)
        cout << "-1\n";
    else
        cout << kol - ans << "\n";

    return 0;
}