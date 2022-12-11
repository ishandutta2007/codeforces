#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, m, k;

int p[N];
int sz[N];
int v1, v2;
int kn[N], len;
int ed[3100][3100];
int root[N];
bool conn[N];
vector <pair<int, int> > e;
set<pair<int, int> > s;

int deg1 = 0;

int fnd(int v) {
    return (v == p[v] ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 != v2) {
        if (sz[v1] == sz[v2])
            sz[v1]++;
        if (sz[v1] > sz[v2])
            p[v2] = v1;
        else
            p[v1] = v2;
    }
}

int rnd() {
    ll res = rand();
    return (res << 16ll) ^ (rand());
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    srand(time(NULL));

    scanf("%d%d%d", &n, &m, &k);

    deg1 = n - 1;

    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        if (v1 > v2) swap(v1, v2);
        v1--;
        v2--;
        e.push_back(make_pair(v1, v2));
        s.insert(make_pair(v1, v2));

        if (v1 == 0) {
            deg1--;
            conn[v2] = true;
        }
    }

    if (deg1 < k) {
        cout << "impossible";
        return 0;
    }

    if (n > -1000) {
        for (int i = 0; true; i++) {
            if (i % 100 == 0) {
                if (clock() > 1000)
                    break;
            }
            v1 = rnd() % (n - 1) + 1;
            v2 = rnd() % (n - 1) + 1;
            if (v1 > v2) swap(v1, v2);
            if (s.find(make_pair(v1, v2)) == s.end())
                uniq(v1, v2);
        }
    }

    for (int i = 1; i < n; i++) {
        if (p[i] == i) {
            root[len] = i;
            kn[i] = len++;
        } else
            kn[i] = -1;
    }

    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            ed[j][i] = ed[i][j] = sz[root[i]] * sz[root[j]];

    for (pair<int,int> q: e) {
        v1 = kn[fnd(q.first)];
        v2 = kn[fnd(q.second)];
        if (v1 == v2)
            continue;
        ed[v1][v2]--;
        ed[v2][v1]--;
    }

    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++)
            if (ed[i][j] > 0)
                uniq(root[i], root[j]);

    for (int i = 1; i < n; i++)
        if (!conn[i])
            conn[fnd(i)] = false;

    int kk = 0;
    for (int i = 1; i < n; i++)
        if (p[i] == i) {
            if (conn[i]) {
                cout << "impossible\n";
                return 0;
            }
            kk++;
        }

    if (kk > k)
        cout << "impossible";
    else
        cout << "possible";

    return 0;
}