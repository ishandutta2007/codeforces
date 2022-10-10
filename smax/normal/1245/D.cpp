#include <bits/stdc++.h>
using namespace std;

int c[2001], k[2001];
bool visited[2001] = {};
pair<int, int> cities[2001];
pair<long long, pair<int, int>> edges[2001];

long long dist(int i, int j) {
    if (i == 0)
        return c[j];
    if (j == 0)
        return c[i];
    long long len = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
    return len * (k[i] + k[j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> cities[i].first >> cities[i].second;
    for (int i=1; i<=n; i++)
        cin >> c[i];
    for (int i=1; i<=n; i++)
        cin >> k[i];

    for (int i=0; i<=n; i++)
        edges[i].first = LLONG_MAX;
    for (int k=0; k<=n; k++) {
        int minI = -1;
        for (int i=0; i<=n; i++)
            if (!visited[i] && (minI == -1 || edges[i].first < edges[minI].first))
                minI = i;
        visited[minI] = true;
        for (int j=0; j<=n; j++)
            if (!visited[j] && dist(minI, j) < edges[j].first)
                edges[j] = make_pair(dist(minI, j), make_pair(minI, j));
    }

    long long ret = 0;
    vector<int> v;
    vector<pair<int, int>> e;
    for (int i=0; i<=n; i++)
        if (edges[i].first != LLONG_MAX) {
            ret += edges[i].first;
            if (edges[i].second.first == 0)
                v.push_back(edges[i].second.second);
            else if (edges[i].second.second == 0)
                v.push_back(edges[i].second.first);
            else
                e.push_back(edges[i].second);
        }

    cout << ret << "\n" << v.size() << "\n";
    for (int i : v)
        cout << i << " ";
    cout << "\n" << e.size() << "\n";
    for (auto p : e)
        cout << p.first << " " << p.second << "\n";

    return 0;
}