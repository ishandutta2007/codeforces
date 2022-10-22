#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int fib[N];
map<int, int> ind;

vector<int> g[N];
int col[N];
int sz[N];
int pr[N];

void dfs1(int v, int par, int cl) {
    sz[v] = 1;
    pr[v] = par;
    for(int u : g[v]) {
        if(col[u] == cl && u != par) {
            dfs1(u, v, cl);
            sz[v] += sz[u];
        }
    }
}

void dfs2(int v, int par, int cl, int new_cl) {
    col[v] = new_cl;

    for(int u : g[v]) {
        if(col[u] == cl && u != par) {
            dfs2(u, v, cl, new_cl);
        }
    }
}

int cur = 0;

void solve(int cl, /*int root*/ vector<int> a) {
//    cout << "solve cl = " << cl << endl;
//    cout << "a : ";
//    for(int x : a)
//        cout << x << ' ';
//    cout << endl;
    int root = a[0];
    dfs1(root, -1, cl);

    int j = -1;
    if(ind.count(sz[root]) == 0) {
        NO();
    } else {
        j = ind[sz[root]];
    }

    if(sz[root] == 1)
        return;

    vector<int> b, c;
    for(int v : a) {
        if(sz[v] == fib[j - 2] || sz[v] == fib[j - 1]) {
            int cl1 = ++cur;
            int cl2 = ++cur;
            dfs2(v, pr[v], cl, cl1);
            dfs2(pr[v], v, cl, cl2);

            for(int u : a) {
                if(col[u] == cur - 1)
                    b.push_back(u);
                else
                    c.push_back(u);
            }

            solve(cl1, b);
            solve(cl2, c);

            return;
        }
    }

    NO();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    fib[0] = 1, fib[1] = 1;
    ind[fib[1]] = 1;
    for(int i = 2; ; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        ind[fib[i]] = i;
        if(fib[i] > n)
            break;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = i;

    solve(0, a);

    cout << "YES" << endl;
}