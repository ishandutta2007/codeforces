#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)x.size())
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()

typedef long long ll;

void make_tree(int v, int par, vector<vector<int>> &gr, vector<int> &pr) {
    if (pr[v] == -2) {
        pr[v] = par;
        for (auto w : gr[v]) make_tree(w, v, gr, pr);
    }
}

bool dfs(int from, int to, int par, vector<vector<int>> &gr, vector<int> &pth) {
    if (from == to) {
        pth.push_back(to);
        return true;
    }
    for (auto w : gr[from]) {
        if (w == par) continue;
        if (dfs(w, to, from, gr, pth)) {
            pth.push_back(from);
            return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    ll pw = 1;
    int lg = 0;

    while (pw < n) {
        lg++;
        pw *= k;
    }

    cout << lg << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pw = k, lg = 1;
            while ((i / pw) != (j / pw)) {
                pw *= k;
                lg++;
            }
            cout << lg << ' ';
        }
    }
    cout << endl;

    return 0;
}