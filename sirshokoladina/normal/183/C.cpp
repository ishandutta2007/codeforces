#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const long double pi = 3.1415926535897932384626433832795028841971l;

int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

vector<int> e[100010];
vector<int> f[100010];
int c[100010];

int ans = 0;

void dfs(int v, int k) {
    if (c[v] != -1) {
        ans = gcd(ans, abs(c[v] - k));
        return;
    }
    c[v] = k;
    forn (i, e[v].size()) {
        dfs(e[v][i], k + 1);
    }
    forn (i, f[v].size()) {
        dfs(f[v][i], k - 1);
    }
}

int main() {
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    int n, m;
    cin >> n >> m;
    forn (i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].pb(y);
        f[y].pb(x);
    }
    memset(c, -1, sizeof c);
    forn (i, n) {
        if (c[i] == -1) {
            dfs(i, 1000000000);
        }
    }
    if (ans == 0) {
        ans = n;
    }
    cout << ans;
        return 0;
}