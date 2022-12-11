#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 34;
int n, m, v1[N], v2[N];
int di[N];
vector <int> es[N];
int cur, w, ncur;
int pos[N];

void fail() {
    cout << -1;
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1[i], &v2[i]);
        v1[i]--;
        v2[i]--;
        es[v1[i]].push_back(v2[i]);
        di[v2[i]]++;
        //cerr << v1[i] << " " << v2[i] << "\n";
    }
    cur = -1;
    for (int i = 0; i < n; i++)
    if (di[i] == 0) {
        if (cur != -1)
            fail();
        cur = i;
    }

    for (int i = 0; i < n; i++) {
        if (cur < 0) return 2;
        pos[cur] = i;
        //cerr << cur + 1 << " ";
        if (i + 1 == n)
            break;
        ncur = -1;
        for (int j = 0; j < es[cur].size(); j++) {
            w = es[cur][j];
            //cerr << "w = " << w << " ";
            di[w]--;
            if (di[w] == 0) {
                if (ncur != -1)
                    fail();
                ncur = w;
            }
        }
        cur = ncur;
    }

    for (int i = m - 1; i >= 0; i--)
        if (pos[v1[i]] + 1 == pos[v2[i]]) {
            cout << i + 1;
            return 0;
        }

    return 0;
}