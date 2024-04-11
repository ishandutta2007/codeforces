// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
const long long LM = 1LL << 60;
using P = pair<long long, int>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<P>> edge(n);
    vector<vector<P>> rev(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        edge[u].emplace_back(w, v);
        rev[v].emplace_back(w, u);
    }
    vector<long long> d1(n, LM);
    d1[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(d1[0], 0);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (p.first != d1[p.second]) continue;
        for (auto& e : edge[p.second]) {
            if (d1[e.second] > p.first + e.first) {
                d1[e.second] = p.first + e.first;
                pq.emplace(d1[e.second], e.second);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        pq.emplace(d1[i], i);
    }
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (p.first != d1[p.second]) continue;
        for (auto& e : rev[p.second]) {
            if (d1[e.second] > p.first + e.first) {
                d1[e.second] = p.first + e.first;
                pq.emplace(d1[e.second], e.second);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << (d1[i] == LM ? -1 : d1[i]) << (i < n - 1 ? ' ' : '\n');
    }



    return 0;
}