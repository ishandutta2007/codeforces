#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int M = 1e3 + 10, A = 26;
int n, k;

vector<int> g[A];
vector<string> have;

void no() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void addEdges(string a, string b) {
    for (int i = 0; i < min(a.size(), b.size()); ++i) {
        if (a[i] == b[i]) continue;
        g[a[i] - 'a'].push_back(b[i] - 'a');
        return;
    }
    if (a.size() > b.size()) {
        //cout << a << " | " << b << endl;
        no();
    }
}

bool used[A];

void read() {
    cin >> n >> k;
    have.resize(n * k);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < k; ++j) {
            cin >> have[x * k + j];
        }
    }
    for (int i = 0; i + 1 < n * k; ++i) {
        addEdges(have[i], have[i + 1]);
    }
    for (auto i : have) {
        for (auto j : i) {
            assert(j >= 'a' && j <= 'z');
            used[j - 'a'] = 1;
        }
    }
}

vector<int> order;
int color[A];

void dfs(int v) {
    color[v] = 1;
    for (auto i : g[v]) {
        if (color[i] == 1) no();
        if (color[i] == 2) continue;
        dfs(i);
    }
    color[v] = 2;
    order.push_back(v);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20);
    read();
    for (int i = 0; i < A; ++i) {
        if (used[i] && color[i] != 2) {
            dfs(i);
        }
    }
    reverse(all(order));
    for (auto i : order) {
        cout << static_cast<char>('a' + i);
    }
    cout << endl;
    return 0;
}