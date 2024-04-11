#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
int n, m, k;
vector<pair<pair<int,int>,int>> edg;
vector<vector<pair<int, int>>>  z;
vector<int> deg;
vector <vector<int>> gt;
int ans = 0;
vector<int> nabor;
set<pair<pair<int,int>,pair<int,int>>> ban;
set<pair<int, int>> permach;

void brute(int i) {
    if (i == k + 1) {
        ans++;
        //for (auto num : nabor) cout << num << ' ';
        //cout << '\n';
        return;
    }
    for (int kto = 0; kto < i; kto++) {
        if (permach.find({i, kto}) == permach.end()) {
            nabor[i] = kto;
            bool ok = true;
            for (int j = 0; j < i; j++) {
                if (ban.find({{j, nabor[j]},
                              {i, nabor[i]}}) != ban.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                brute(i + 1);
            }
            nabor[i] = -1;
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    z.resize(n);
    edg.resize(m);
    deg.resize(n);
    gt.resize(n);
    nabor.resize(k + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edg.pb({{a, b}, w});
        gt[b].pb(i);
        deg[a]++;
        z[a].pb({w, i});
    }
    for (int v = 0; v < n; v++) {
        sort(z[v].begin(), z[v].end());
    }
    vector <pair<int, int>> ex(m);
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < z[v].size(); i++) {
            ex[z[v][i].second] = {deg[v], i};
        }
    }
    for (int v = 0; v < n; v++) {
        set<pair<int, int>> zlo;
        for (auto i : gt[v]) {
            if (zlo.find(ex[i]) != zlo.end()) permach.insert(ex[i]);
            zlo.insert(ex[i]);
        }
        vector<pair<int, int>> vg;
        for (auto p : zlo) vg.pb(p);
        for (int i = 0; i < vg.size(); i++) {
            for (int j = i + 1; j < vg.size(); j++) {
                ban.insert({vg[i], vg[j]});
                ban.insert({vg[j], vg[i]});
            }
        }
    }
    brute(1);
    cout << ans << '\n';

}