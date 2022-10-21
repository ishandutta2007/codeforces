#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3")
#include<bits/stdc++.h>
using namespace std;

#define N 200010
#define M 60

int n, m, p;
bitset<N> b[M];
char s[M];
vector<int> v;

bitset<N> x;
bitset<M> vis, ans;

bitset<M> &MAX(bitset<M> &a, bitset<M> &b) {
    return a.count() < b.count() ? b : a;
}

void find(int k, int d) {
    if(k == d) {
        if(x.count() * 2 >= n) ans = MAX(ans, vis);
        return;
    }
    if(x.count() * 2 < n) return;
    if(k - vis.count() >= d - ans.count()) return;
    bitset<N> y = x;
    vis[v[k]] = 1;
    x &= b[v[k]];
    find(k + 1, d);
    vis[v[k]] = 0;
    x = y;
    find(k + 1, d);
}

int main() {
    srand(time(0));
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < n; i ++) {
        scanf("%s", &s);
        for(int j = 0; j < m; j ++) b[j][i] = s[j] == '1';
    }
    for(int t = 10; t --; ) {
        int k = (rand() << 15 | rand()) % n;
        v.clear();
        for(int i = 0; i < m; i ++) if(b[i][k]) v.push_back(i);
        x.set(); vis.reset();
        find(0, v.size());
    }
    for(int i = 0; i < m; i ++) cout << ans[i]; cout << endl;
}