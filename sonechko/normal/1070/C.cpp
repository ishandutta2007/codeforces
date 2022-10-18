#include<bits/stdc++.h>
#define y1 kdfjdfldsfbjd
using namespace std;
const int N = 1e6 + 5;
int n, k, m, t, sz;
vector < pair < int , pair < int , int > > > g[N];
long long tree1[N * 4];
long long tree2[N * 4];

void add(int v, int x){
    tree1[v] += x;
    tree2[v] = 1ll * tree1[v] * (v - sz + 1);
    v >>= 1;
    while (v > 0){
        tree1[v] = tree1[v + v] + tree1[v + v + 1];
        tree2[v] = tree2[v + v] + tree2[v + v + 1];
        v >>= 1;
    }
}

long long get(int v, int l, int r, long long k){
    if (tree1[v] <= k)return tree2[v];
    if (l == r){
        return 1ll * k * (l - sz + 1);
    }
    int mid = (l + r) / 2;
    if (tree1[v + v] >= k)return get(v + v, l, mid, k);else return tree2[v + v] + get(v + v + 1, mid + 1, r, k - tree1[v + v]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >>n>>k>>m;
    for (int i = 1; i <= m; ++i){
        int l, r, c, p;
        cin >>l>>r>>c>>p;
        g[l].push_back(make_pair(1, make_pair(c, p)));
        g[r + 1].push_back(make_pair(-1, make_pair(c, p)));
    }
    sz = 1;
    while (sz < 1000000){
        sz *= 2;
    }
    long long ans = 0, s = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < g[i].size(); ++j){
            int c = g[i][j].second.first, p = g[i][j].second.second;
            add(sz + p - 1, c * g[i][j].first);
        }
        ans += get(1, sz, sz + sz - 1, k);
    }
    cout <<ans;
}