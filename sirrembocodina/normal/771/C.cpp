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

vector<int> g[200100];
int cnt[200100][6];
int scnt[200100];
long long sum[200100];
int n, k;
long long ans = 0;
long long rans[6];

void dfs(int v, int p = -1) {
    forn (i, k) {
        cnt[v][i] = 0;
    }
    cnt[v][0] = 1;
    sum[v] = 0;
    scnt[v] = 1;
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs(to, v);
        ans += sum[v] * scnt[to];
        ans += (sum[to] + scnt[to]) * scnt[v];
        forn (j, k) {
            forn (l, k) {
                rans[(j + l + 1) % k] += cnt[v][j] * (long long)(cnt[to][l]);
            }
        }
        sum[v] += sum[to] + scnt[to];
        scnt[v] += scnt[to];
        forn (j, k) {
            cnt[v][(j + 1) % k] += cnt[to][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
//        x = i + 1;
//        y = i + 2;
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    forn (i, k) {
        rans[i] = 0;
    }
    dfs(0);
    forn (i, k) {
        ans += ((k - i) % k) * rans[i];
    }
    cout << ans / k << endl;
    return 0;
}