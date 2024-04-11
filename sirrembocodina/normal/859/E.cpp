#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

const long long mod = 1000000007;

vector<int> p, s[200100];
vector<int> d;
vector<int> used;
bool cycle = false;
int col = 0;

void dfs(int v) {
    used[v] = col;
    forn (i, s[v].size()) {
        int to = s[v][i];
        if (used[to] == -1) {
            dfs(to);
        } else if (used[to] == col && to != v) {
            cycle = true;
        }
        d[v] += d[to];
    }
//    cerr << v << " " << d[v] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> m;
    n = 2 * m;
    p.resize(n, -1);
    d.resize(n, 1);
    used.resize(n, -1);
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        p[x] = y;
        s[y].pb(x);
    }
    long long ans = 1;
    forn (i, n) {
        if (used[i] != -1) {
            continue;
        }
        cycle = false;
        dfs(i);
        ++col;
        if (cycle) {
            ans *= 2;
            ans %= mod;
        }
    }
//    cerr << endl;
    forn (i, n) {
//        cerr << d[i] << " " << p[i] << endl;
        if (p[i] == -1) {
            ans *= d[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}