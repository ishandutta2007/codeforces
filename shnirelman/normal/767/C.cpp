//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

vector<int> g[N];
int a[N];
int x;
int dp[N];
int root = -1;

vector<int> dfs(int v) {
    dp[v] = a[v];

    vector<int> res;
    for(auto u : g[v]) {
        auto rs = dfs(u);
        for(auto w : rs)
            res.push_back(w);
        dp[v] += dp[u];
    }

    if(res.size() >= 2) {
        cout << res[0] + 1 << ' ' << res[1] + 1 << endl;
        exit(0);
    }

    if(res.size() == 1 && dp[v] == x * 2 && v != root) {
        cout << res[0] + 1 << ' ' << v + 1 << endl;
        exit(0);
    }

    if(res.empty() && dp[v] == x)
        res.push_back(v);

    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    int s = 0;
    for(int i = 0; i < n; i++) {
        int par;
        cin >> par >> a[i];

        par--;

        if(par == -1)
            root = i;
        else
            g[par].push_back(i);

        s += a[i];
    }

    if(s % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    x = s / 3;

    dfs(root);

    cout << -1 << endl;
}