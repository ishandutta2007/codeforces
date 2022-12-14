#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 200005;
int n, m, k, l[N], r[N], choice[N], good[N];
vector<int> Q;
string s;

void visit(int u) {
    if (!u) return;
    visit(l[u]);
    Q.push_back(u);
    visit(r[u]);
}

void DFS(int u, int h) {
    if (!u) return;
    if (h > k) return;
    DFS(l[u], h + 1);
    if (choice[l[u]]) h = 0;
    if (choice[l[u]] || good[u]) {
        choice[u] = 1;
        k -= h;
        DFS(r[u], 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k >> s; s = ' ' + s;
    FOR(i, 1, n) cin >> l[i] >> r[i];
    visit(1);
    char last_diff = 'a';
    FORD(i, n - 2, 0) {
        int u = Q[i], v = Q[i + 1];
        if (s[u] != s[v]) {
            last_diff = s[v];
        }
        if (s[u] < last_diff) good[u] = true;
    }
    DFS(1, 1);
    REP(i, 0, n) {
        int u = Q[i];
        cout << s[u];
        if (choice[u]) cout << s[u];
    }
}