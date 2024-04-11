#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define TASKNAME ""

vector<vector<int>> gr;
map<pair<int, int>, bool> was;
vector<int> cnt;
vector<bool> group;

void relax(set<pair<int, int>> &data, int &m, int &n, int &k) {
    while (!data.empty() && data.begin()->first < k) {
        int v = data.begin()->second;
        data.erase(data.begin());
        group[v] = 0;
        cnt[v] = 0;
        for (int to: gr[v]) {
            if (was[{v, to}]) {
                continue;
            }
            if (!group[to]) {
                continue;
            }
            data.erase({cnt[to], to});
            cnt[to]--;
            data.insert({cnt[to], to});
            was[{to, v}] = 1;
            was[{v, to}] = 1;
        }
    }
}

int main() {
#ifdef MY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //    freopen(TASKNAME".in", "r", stdin);
    //    freopen(TASKNAME".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> ask;
    gr.resize(n);
    cnt.resize(n, 0);
    group.resize(n, 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
        ask.push_back({a, b});
    }
    set<pair<int, int>> data;
    for (int i = 0; i < n; ++i) {
        data.insert({cnt[i], i});
    }
    vector<int> ans;
    for (int i = m - 1; i >= 0; --i) {
        relax(data, m, n, k);
        ans.push_back(data.size());
        int a = ask[i].first, b = ask[i].second;
        if (group[a] && group[b]) {
            data.erase({cnt[a], a});
            data.erase({cnt[b], b});
            --cnt[a];
            --cnt[b];
            data.insert({cnt[a], a});
            data.insert({cnt[b], b});
        }
        was[{a, b}] = 1;
        was[{b, a}] = 1;
    }
    for (int i = m - 1; i >= 0; --i) {
        cout << ans[i] << "\n";
    }
}