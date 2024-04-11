#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

vector<int> g[100100];
bool used[100100];

ll m, x;
ll d[11][100100], dl[11][100100], dn[11][100100];

void dfs(int v) {
    used[v] = true;
    vector<int> sons;
    forn (i, g[v].size()) {
        int to = g[v][i];
        if (used[to]) {
            continue;
        }
        sons.pb(to);
        dfs(to);
    }
    
    int ss = sons.size();
    
    if (ss == 0) {
        d[0][v] = m - 1;
        d[1][v] = 1;
        dn[0][v] = m - 1;
        dl[0][v] = x - 1;
        return;
    }
    
    vector<vector<ll> > subl(ss + 1, vector<ll>(11, 0ll));
    subl[0][0] = 1;
    forn (i, ss) {
        int to = sons[i];
        forn (j, 11) {
            forn (k, j + 1) {
                subl[i + 1][j] += ll(subl[i][k]) * d[j - k][to];
                subl[i + 1][j] %= mod;
            }
        }
    }
    
    vector<vector<ll> > sube(ss + 1, vector<ll>(11, 0ll));
    sube[0][0] = 1;
    forn (i, ss) {
        int to = sons[i];
        forn (j, 11) {
            forn (k, j + 1) {
                sube[i + 1][j] += ll(sube[i][k]) * dl[j - k][to];
                sube[i + 1][j] %= mod;
            }
        }
    }
    
    vector<vector<ll> > subg(ss + 1, vector<ll>(11, 0ll));
    subg[0][0] = 1;
    forn (i, ss) {
        int to = sons[i];
        forn (j, 11) {
            forn (k, j + 1) {
                subg[i + 1][j] += ll(subg[i][k]) * dn[j - k][to];
                subg[i + 1][j] %= mod;
            }
        }
    }
    
    forn (k, 11) {
        d[k][v] = ((x - 1) * subl[ss][k] +
                   (k == 0 ? 0 : sube[ss][k - 1]) +
                   (m - x) * subg[ss][k]) % mod;
                   
        dl[k][v] = ((x - 1) * subl[ss][k]) % mod;
        
        dn[k][v] = ((x - 1) * subl[ss][k] +
                    (m - x) * subg[ss][k]) % mod;
    }
}

int main() {
    int n;
    cin >> n >> m;
    forn (i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int k;
    cin >> x >> k;
    dfs(0);
    ll ans = 0;
    forn (i, k + 1) {
        ans += d[i][0];
    }
    cout << (ans % mod) << endl;
    return 0;
}