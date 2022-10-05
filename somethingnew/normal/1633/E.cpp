#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
struct dsu {
    vector<int> pr;
    dsu(int n) {
        pr.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            pr[i] = i;
        }
    }
    int getv(int v) {
        if (pr[v]==v)
            return v;
        return pr[v] = getv(pr[v]);
    }
    bool merge(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a != b) {
            pr[b] = a;
            return 1;
        }
        return 0;
    }
};
int globx;
bool cmp(array<int, 3> a, array<int, 3> b) {
    return abs(globx-a[2]) < abs(globx-b[2]);
}
pair<int, int> zpr(int n, vector<array<int, 3>> edges, int x) {
    dsu gr(n);
    globx = x;
    sort(all(edges), cmp);
    int xval = 0, val = 0;
    for (auto [a, b, c] : edges) {
        if (gr.merge(a, b)) {
            if (c <= x) { // x - c
                xval += 1;
                val -= c;
            } else {
                xval -= 1;
                val += c;
            }
        }
    }
    return {xval, val};
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> elel(m);
    vector<array<int, 3>> edges(m);
    vector<int> alel;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        elel[i] = c;
        edges[i] = {a, b, c};
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= i; ++j) {
            int x = (elel[i] + elel[j]) / 2;
            alel.push_back(x);
            alel.push_back(x+1);
            alel.push_back(x-1);
        
        }
    }
    sort(all(alel));
    alel.erase(unique(all(alel)), alel.end());
    vector<pair<int, int>> res(alel.size());
    for (int i = 0; i < alel.size(); ++i) {
        res[i] = zpr(n, edges, alel[i]);
    }
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> zpr(k);
    for (int i = 0; i < p; ++i) {
        cin >> zpr[i];
    }
    for (int i = p; i < k; ++i) {
        zpr[i] = (zpr[i - 1] * a + b) % c;
    }
    sort(all(zpr));
    int ind = 0;
    int xr = 0;
    for (int i = 0; i < k; ++i) {
        while (ind + 1 != res.size() and alel[ind + 1] <= zpr[i])
            ind++;
        //cout << zpr[i] << ' ' << res[ind].second + res[ind].first * zpr[i] << endl;
        xr ^= res[ind].second + res[ind].first * zpr[i];
    }
    cout << xr;
}