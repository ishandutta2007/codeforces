#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > gr;

vector <int> dfs(int v, int p) {
    vector <int> all;
    for (int u : gr[v]) {
        if (u == p) continue;
        auto t = dfs(u, v);
        if (all.size() < t.size()) swap(all, t);
        int now = 0;
        for (int i = all.size() - t.size(); i < all.size(); i++) {
            all[i] = (all[i] + t[now]) % 2;
            now++;
        }
    }
    all.push_back(1);
//    cout << v << "\n";
//    for (int x : all) {
//        cout << x << " ";
//    }
//    cout << "\n";
    return all;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        gr[p].push_back(i);
    }
    int sum = 0;
    auto t = dfs(0, -1);
    for (int x : t) {
        sum += x;
    }
    cout << sum;
}