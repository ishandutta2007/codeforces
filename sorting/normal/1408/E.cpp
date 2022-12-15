#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

struct dsu{
    int sz[k_N], p[k_N];

    dsu(){
        for(int i = 0; i < k_N; ++i){
            sz[i] = 1;
            p[i] = i;
        }
    }

    int get_p(int x){
        if(x == p[x]) return x;
        return p[x] = get_p(p[x]);
    }

    bool unite(int a, int b){
        a = get_p(a);
        b = get_p(b);
        if(a == b) return false;

        if(sz[a] < sz[b])
            swap(a, b);

        sz[a] += sz[b];
        p[b] = a;

        return true;
    }
};

int a[k_N], b[k_N], m, n;
vector<array<int, 3>> e;
dsu d;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        cin >> a[i];
    for(int j = 1; j <= n; ++j)
        cin >> b[j];

    long long ans = 0;
    for(int i = 1; i <= m; ++i){
        int s;
        cin >> s;

        for(int j = 0; j < s; ++j){
            int x;
            cin >> x;

            ans += b[x] + a[i];
            e.push_back(array<int, 3>{-(b[x] +  a[i]), i, m + x});
        }
    }

    sort(e.begin(), e.end());

    for(auto edge: e)
        if(d.unite(edge[1], edge[2]))
            ans += edge[0];

    cout << ans << "\n";
}