#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int last = 0;
map <pair <string, int>, int> id;
vector <pair <string, int> > all;
vector <vector <int> > gr;

void add(string &s, int ver) {
    if (!id.count({s, ver})) {
        id[{s, ver}] = last++;
        all.push_back({s, ver});
        gr.push_back({});
    }
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int ver;
        cin >> s >> ver;
        add(s, ver);
        int m;
        cin >> m;
        int v = id[{s, ver}];
        for (int j = 0; j < m; j++) {
            string s1;
            int ver1;
            cin >> s1 >> ver1;
            add(s1, ver1);
            int u = id[{s1, ver1}];
            gr[v].push_back(u);
        }
        //string tr;
        //cin >> tr;
    }
    map <string, pair <int, int> > d;
    map <string, bool> useds;
    queue <int> q;
    vector <bool> used(n, false);
    d[all[0].first] = {0, all[0].second};
    q.push(0);
    vector <pair <string, int> > res;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        auto sv = all[v].first;
        int ver_v = all[v].second;
        if (d[sv].second != ver_v) continue;
        if (d[sv].first && !useds[sv]) {
            useds[sv] = true;
            res.push_back({sv, d[sv].second});
        }
        for (int u : gr[v]) {
            string su = all[u].first;
            int ver_u = all[u].second;
            if (!d.count(su)) {
                d[su] = {d[sv].first + 1, ver_u};
            } else if (d[su].first == d[sv].first + 1) {
                if (d[su].second < ver_u) {
                    d[su].second = ver_u;
                }
            }
            if (!used[u]) {
                used[u] = 1;
                q.push(u);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first << " " << p.second << "\n";
    }
}