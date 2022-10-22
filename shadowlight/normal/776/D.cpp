#include <bits/stdc++.h>

using namespace std;

vector <int> data;
vector <vector <int> > levers;
vector <pair <int, int> > doors;
vector <int> used;
vector <int> now_doors;
vector <int> used_doors;
set <int> changed;
set <int> changed1;
bool fl = 0;

void dfs(int v, int sost) {
    if (sost == 1) {
        changed.insert(v);
    }
    if (used[v] && used[v] != sost) {
        fl = 1;
        return;
    } else if (used[v]) {
        return;
    }
    used[v] = sost;
    for (int u : levers[v]) {
        changed1.insert(u);
        int k;
        if (doors[u].first == v) {
            k = doors[u].second;
        } else {
            k = doors[u].first;
        }
        if (sost == 1) {
            now_doors[u] *= -1;
        }
        used_doors[u]++;
        if (used_doors[u] == 2) continue;
        dfs(k, now_doors[u] * -1);
        if (fl) {
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    data.resize(n, 0);
    levers.resize(m);
    used.resize(m, 0);
    used_doors.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        if (!data[i]) --data[i];
    }
    doors.resize(n, {-1, -1});
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            levers[i].push_back(x);
            if (doors[x].first == -1) {
                doors[x].first = i;
            } else {
                doors[x].second = i;
            }
        }
    }
    now_doors = data;
    for (int i = 0; i < n; i++) {
        if (now_doors[i] == -1) {
            fl = 0;
            dfs(doors[i].first, 1);
            if (!fl) continue;
            fl = 0;
            while (!changed.empty()) {
                int v = *changed.begin();
                changed.erase(v);
                used[v] = 0;
            }
            while (!changed1.empty()) {
                int v = *changed1.begin();
                changed1.erase(v);
                now_doors[v] = data[v];
                used_doors[v] = 0;
            }
            dfs(doors[i].first, -1);
            if (!fl) continue;
            cout << "NO";
            return 0;
        }
        changed.clear();
        changed1.clear();
    }
    cout << "YES" << endl;
}
/*
1 2
0
1 1
1 1
*/