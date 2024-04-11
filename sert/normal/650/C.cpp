#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

vector <int> a[N], ek[N];
vector <pair<int, int> > v, es[N];

int code[N], din[N], w, to, we;
int k[N], kk, n, m, x;
queue<int> q;

void fnd_k(int v) {
    if (k[v] != -1)
        return;
    k[v] = kk;
    for (int i = 0; i < es[v].size(); i++)
        if (es[v][i].second == 0)
            fnd_k(es[v][i].first);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        v.clear();
        for (int j = 0; j < m; j++) {
            v.push_back(make_pair(a[i][j], i * m + j));
        }
        sort(v.begin(), v.end());
        for (int j = 1; j < v.size(); j++) {
            if (v[j - 1].first == v[j].first) {
                es[v[j - 1].second].push_back(make_pair(v[j].second, 0));
                es[v[j].second].push_back(make_pair(v[j - 1].second, 0));
            } else {
                es[v[j - 1].second].push_back(make_pair(v[j].second, 1));
            }
        }
    }

    for (int j = 0; j < m; j++) {
        v.clear();
        for (int i = 0; i < n; i++)
            v.push_back(make_pair(a[i][j], i * m + j));
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1].first == v[i].first) {
                es[v[i - 1].second].push_back(make_pair(v[i].second, 0));
                es[v[i].second].push_back(make_pair(v[i - 1].second, 0));
            } else {
                es[v[i - 1].second].push_back(make_pair(v[i].second, 1));
                //din[v[i].second]++;
            }
        }
    }

    for (int i = 0; i < n * m; i++)
        k[i] = -1;

    for (int i = 0; i < n * m; i++)
        if (k[i] == -1) {
            fnd_k(i);
            kk++;
        }

    /*for (int i = 0; i < n * m; i++) {
        cout << k[i] << " ";
        if (i % n == n - 1) cout << "\n";
    }*/


    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < es[i].size(); j++)
            if (es[i][j].second == 1)
                ek[k[i]].push_back(k[es[i][j].first]);
    }

    for (int i = 0; i < kk; i++)
        for (int j = 0; j < ek[i].size(); j++)
            din[ek[i][j]]++;

    for (int i = 0; i < kk; i++)
        if (din[i] == 0) {
            code[i] = 1;
            q.push(i);
        }

    while (!q.empty()) {
        w = q.front();
        q.pop();
        for (int i = 0; i < ek[w].size(); i++) {
            to = ek[w][i];
            din[to]--;
            if (din[to] == 0) {
                code[to] = code[w] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", code[k[i * m + j]]);
        printf("\n");
    }



    return 0;
}