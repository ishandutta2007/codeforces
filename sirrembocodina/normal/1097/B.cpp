#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

vector<int> g[400100];
bool used[400100];

void dfs(int v) {
    used[v] = true;
    forn (i, g[v].size()) {
        if (!used[g[v][i]]) {
            dfs(g[v][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n = 1000;                         
    cin >> n;
    int a[100];
    forn (i, n) {
        cin >> a[i];
    }
    forn (mask, 1 << n) {
        int sum = 0;
        forn (i, n) {
            if (mask & (1 << i)) {
                sum += a[i];
            } else {
                sum -= a[i];
            }
        }
        if (sum % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
            cout << "NO" << endl;
    return 0;
}