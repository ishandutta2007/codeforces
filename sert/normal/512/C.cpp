#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

struct Edge {
    Edge() {}
    Edge(int v, int w, int c) {
        v1 = v;
        v2 = w;
        oc = c;
    }
    int v1, v2;
    int oc;
};

int n, a[N], num, kl, t, st, pr, h;
Edge e[N];
vector <pair<int, int> > es[N];
vector <int> fin[N], ans[N];
bool u[N], uv[N];
stack <int> sv, sr;
bool fnd;

void go(int v) {
    if (v == n + 1) {
        fnd = true;
        return;
    }
    uv[v] = true;

    sr.push(-1);
    int w;
    for (int i = 0; !fnd && i < es[v].size(); i++) {
        w = es[v][i].second;
        if (e[w].oc == 1 && !uv[e[w].v2]) {
            sr.top() = w;
            go(e[w].v2);
        }
    }
    if (!fnd)
        sr.pop();
}

bool flow() {
    for (int i = 0; i < n + 2; i++) uv[i] = false;
    while (!sv.empty()) sv.pop();
    while (!sr.empty()) sr.pop();
    fnd = false;
    go(n);

    while (!sr.empty()) {
        e[sr.top()].oc = 0;
        e[sr.top() ^ 1].oc = 1;
        sr.pop();
    }

    return fnd;
}

int kch;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    u[0] = u[1] = true;
    for (int i = 2; i < 20000; i++)
        if (u[i]) continue;
        else for (int j = i * i; j < 20000; j += i)
            u[j] = true;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) kch++;
    }

    if (kch * 2 != n) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (a[i] % 2 == 0 && !u[a[i] + a[j]] && a[j] % 2 == 1) {
                es[i].push_back(make_pair(j, num));
                e[num++] = Edge(i, j, 1);
                es[j].push_back(make_pair(i, num));
                e[num++] = Edge(j, i, 0);
            }
        }

    //cerr << num << "\n";

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0) {
            es[n].push_back(make_pair(i, num));
            e[num++] = Edge(n, i, 1);
            es[i].push_back(make_pair(n, num));
            e[num++] = Edge(i, n, 0);

            es[n].push_back(make_pair(i, num));
            e[num++] = Edge(n, i, 1);
            es[i].push_back(make_pair(n, num));
            e[num++] = Edge(i, n, 0);
        } else {
            es[i].push_back(make_pair(n + 1, num));
            e[num++] = Edge(i, n + 1, 1);
            es[n + 1].push_back(make_pair(i, num));
            e[num++] = Edge(n + 1, i, 0);

            es[i].push_back(make_pair(n + 1, num));
            e[num++] = Edge(i, n + 1, 1);
            es[n + 1].push_back(make_pair(i, num));
            e[num++] = Edge(n + 1, i, 0);
        }

    //cerr << num << "\n";

    for (int i = 0; i < n; i++) {
        //cerr << i << "\n";
        if (!flow()) {
            //cerr << i << " ";
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < num; i++)
        if (e[i].v1 < n && e[i].v2 < n && e[i].oc == 0 && a[e[i].v1] % 2 == 0)
            fin[e[i].v1].push_back(e[i].v2);
        else if (e[i].v1 < n && e[i].v2 < n && e[i].oc == 1 && a[e[i].v1] % 2 == 1)
            fin[e[i].v1].push_back(e[i].v2);

    //for (int i = 0; i< n; i++) cerr << fin[i].size() << " ss\n";

    bool u1[N];
    for (int i = 0; i< n; i++) u1[i] = false;
    for (int i = 0; i < n; i++)
    if (!u1[i]) {
        u1[i] = true;
        st = i;
        t = fin[i][0];
        pr = i;
        ans[kl].push_back(st);
        while (t != st) {
            ans[kl].push_back(t);
            u1[t] = true;
            h = t;
            t = fin[t][0] + fin[t][1] - pr;
            pr = h;
        }
        kl++;
    }

    cout << kl << "\n";

    for (int i = 0; i < kl; i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] + 1 << " ";
        cout << "\n";
    }

    return 0;
}