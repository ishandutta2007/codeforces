// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;
const long long LM = 1LL << 60;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m;
        cin >> n >> m;
        vector<P> treeedges(n - 1);
        vector<vector<P>> edge(n);
        vector<vector<P>> edge2(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            treeedges[i] = { u, v };
            if (w != -1) {
                edge[u].emplace_back(w, v);
                edge[v].emplace_back(w, u);
            }
        }
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            edge2[u].emplace_back(w, v);
            edge2[v].emplace_back(w, u);
        }
        vector<int> val(n, -1);
        vector<int> val2(n, -1);
        for (int i = 0; i < n; ++i) {
            if (val[i] != -1) continue;
            val[i] = 0;
            deque<int> q;
            q.push_back(i);
            while (!q.empty()) {
                int p = q.front();
                q.pop_front();
                if (p < 0) {
                    p = ~p;
                    if (val[p] != -1) {
                        if (__builtin_parity(val[p] ^ val2[p]) != 0) {
                            cout << "NO\n";
                            goto A;
                        }
                        continue;
                    }
                    else {
                        val[p] = val2[p];
                    }
                }
                for (auto& e : edge[p]) {
                    if (val[e.second] != -1) {
                        if (val[e.second] != (val[p] ^ e.first)) {
                            cout << "NO\n";
                            goto A;
                        }
                    }
                    else {
                        val[e.second] = val[p] ^ e.first;
                        q.push_front(e.second);
                    }
                }
                for (auto& e : edge2[p]) {
                    if (val[e.second] != -1) {
                        if (__builtin_parity(val[e.second] ^ val[p]) != e.first) {
                            cout << "NO\n";
                            goto A;
                        }
                    }
                    else {
                        if (val2[e.second] != -1) {
                            if (__builtin_parity(val2[e.second] ^ val[p]) != e.first) {
                                cout << "NO\n";
                                goto A;
                            }
                        }
                        else {
                            val2[e.second] = val[p] ^ e.first;
                            q.push_back(~e.second);
                        }
                    }
                }
            }
        }
        cout << "YES\n";
        for (auto& i : treeedges) {
            cout << i.first + 1 << ' ' << i.second + 1 << ' ' << (val[i.first] ^ val[i.second]) << '\n';
        }

        A: continue;
    }

    return 0;
}