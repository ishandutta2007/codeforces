// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
using P = pair<int, int>;

vector<int> get_sieve(int n) {
    vector<int> p(n);
    for (int i = 2; i < n; ++i) {
        p[i] = i;
    }
    for (int i = 2; i * i < n; ++i) {
        if (p[i] == i) {
            for (int j = i * i; j < n; j += i) {
                p[j] = min(p[j], i);
            }
        }
    }
    return p;
}


long long powmod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return res;
}


vector<int> sieve;
vector<long long> invs;


void dfs(int p, int par, const vector<vector<pair<P, int>>>& edge, vector<int>& nowcnt, vector<int>& mincnt) {
    for (auto& e : edge[p]) {
        if (e.second == par) continue;
        vector<int> v;
        {
            int x = e.first.first;
            while (x > 1) {
                int pr = sieve[x];
                --nowcnt[pr];
                v.push_back(pr);
                x /= pr;
            }

            int y = e.first.second;
            while (y > 1) {
                int pr = sieve[y];
                ++nowcnt[pr];
                y /= pr;
            }
        }
        for (auto& i : v) {
            mincnt[i] = min(mincnt[i], nowcnt[i]);
        }
        dfs(e.second, p, edge, nowcnt, mincnt);

        {
            int x = e.first.first;
            while (x > 1) {
                int pr = sieve[x];
                ++nowcnt[pr];
                x /= pr;
            }

            int y = e.first.second;
            while (y > 1) {
                int pr = sieve[y];
                --nowcnt[pr];
                y /= pr;
            }
        }

    }
}

long long ans;

void dfs2(int p, int par, const vector<vector<pair<P, int>>>& edge, long long val) {
    ans = (ans + val) % M;
    for (auto& e : edge[p]) {
        if (e.second == par) continue;
        dfs2(e.second, p, edge, val * invs[e.first.first] % M * e.first.second % M);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    sieve = get_sieve(200010);
    invs = vector<long long>(200010);
    for (int i = 1; i < 200010; ++i) {
        invs[i] = powmod(i, M - 2);
    }

    int T;
    cin >> T;

    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<vector<pair<P, int>>> edge(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            --u;
            --v;
            edge[u].emplace_back(P(x, y), v);
            edge[v].emplace_back(P(y, x), u);
        }
        vector<int> nowcnt(n + 1), mincnt(n + 1);
        dfs(0, -1, edge, nowcnt, mincnt);
        long long val = 1;
        for (int i = 0; i < n + 1; ++i) {
            if (mincnt[i] < 0) {
                val = val * powmod(i, -mincnt[i]) % M;
            }
        }
        ans = 0;
        dfs2(0, -1, edge, val);
        cout << ans << '\n';


    }
    return 0;
}