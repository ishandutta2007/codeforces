#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n, m;

struct query{
    int r, id;
};

struct range {
    int l, r;
};

struct BIT {
    int bit[N];
    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
}bit;

int num[N], ocu[N];
vector<int> rg[N];
vector<query> qry[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    memset(ocu, -1, sizeof(ocu));
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        ocu[num[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(ocu[i] == -1) continue;
        for(int j = i; j <= n; j += i) {
            if(ocu[j] != -1) {
                rg[min(ocu[i], ocu[j])].push_back(max(ocu[i], ocu[j]));
            }
        }
    }
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--; qry[l].push_back({r, i});
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int nxt : rg[i]) bit.add(nxt, 1);
        for(auto p : qry[i]) {
            res[p.id] = bit.get(p.r);
        }
    }
    for(int i = 0; i < m; i++) cout << res[i] << "\n";
}