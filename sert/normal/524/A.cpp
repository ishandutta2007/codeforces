#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 34;

int n, k, len;
vector <int> es[N];
int id[N];
map <int, int> m;
bool a[200][200];
vector <int> ans[N];
int kf, kff, id1, id2, v1, v2;
int p[200];

bool cmp(int a1, int a2) {
    return id[a1] < id[a2];
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> id1 >> id2;
        if (m.find(id1) == m.end()) {
            id[len] = id1;
            m[id1] = len++;
        }
        if (m.find(id2) == m.end()) {
            id[len] = id2;
            m[id2] = len++;
        }
        v1 = m[id1];
        v2 = m[id2];
        //es[v1].push_back
        //cerr << v1 << " " << v2 << "\n";
        a[v1][v2] = a[v2][v1] = true;
    }

    for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++) {
        if (i == j) continue;
        if (a[i][j]) continue;
        kf = 0;
        kff = 0;
        for (int num = 0; num < len; num++) {
            if (num == i || num == j)
                continue;
            if (a[i][num]) kf++;
            if (a[i][num] && a[j][num]) kff++;
        }
        if (kff * 100 >= k * kf)
            ans[i].push_back(id[j]);
    }

    for (int i = 0; i < len; i++)
        p[i] = i;

    sort(p, p + len, cmp);

    for (int i = 0; i < len; i++) {
        cout << id[p[i]] << ": ";
        cout << ans[p[i]].size();
        sort(ans[p[i]].begin(), ans[p[i]].end());
        for (int j = 0; j < ans[p[i]].size(); j++)
            cout << " " << ans[p[i]][j];
        cout << "\n";
    }

    return 0;
}