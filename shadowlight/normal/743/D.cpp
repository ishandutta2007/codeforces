#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17 + 7;

vector <vector <long long> > gr;
vector <long long> data;
vector <long long> sum;
vector <long long> maxk;
long long ans = -INF;
void dfs(long long v, long long pr) {
    sum[v] = data[v];
    long long maxk1 = -INF, maxk2 = -INF;
    for (long long u : gr[v]) {
        if (u == pr) continue;
        dfs(u, v);
        sum[v] += sum[u];
        maxk[v] = max(maxk[v], maxk[u]);
        if (maxk[u] >= maxk1) {
            maxk2 = maxk1;
            maxk1 = maxk[u];
        } else if (maxk[u] > maxk2) {
            maxk2 = maxk[u];
        }
    }
    if (maxk2 != -INF) ans = max(ans, maxk1 + maxk2);
    maxk[v] = max(maxk[v], sum[v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    data.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> data[i];
    }
    gr.resize(n);
    for (long long i = 1; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        gr[l - 1].push_back(r - 1);
        gr[r - 1].push_back(l - 1);
    }
    sum.resize(n, 0);
    maxk.resize(n, -INF);
    dfs(0, -1);
    if (ans == -INF) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
}