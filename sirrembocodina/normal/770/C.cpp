#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

vector<int> g[100100];
int a[100100];
vector<int> ans;
char used[100100];

void dfs(int v) {
    used[v]++;
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (used[to] == 1) {
            cout << "-1\n";
            exit(0);
        }
        if (used[to]) {
            continue;
        }
        dfs(to);
    }
    used[v]++;
    ans.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, k) {
        cin >> a[i];
        --a[i];
    }
    forn (i, n) {
        int sz;
        cin >> sz;
        forn (j, sz) {
            int x;
            cin >> x;
            --x;
            g[i].push_back(x);
        }
    }
    forn (i, k) {
        if (!used[a[i]]) {
            dfs(a[i]);
        }
    }
    cout << ans.size() << endl;
    forn (i, ans.size()) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}