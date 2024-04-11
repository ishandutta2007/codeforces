#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
vector<vector<int>> g;
int mod = 1000000007;
vector<int> nums;
vector<int> nw;
int n;
int makenw(int v, int p){
    nw[v] = 1;
    for (auto x : g[v]) {
        if(x==p)
            continue;
        nw[v] += makenw(x,v);
    }
    return nw[v];
}
void dfs(int v, int p){
    if(v){
        int oth = n - nw[v];
        nums[v] = oth * nw[v];
    }
    for (auto x : g[v]) {
        if(x==p)
            continue;
        dfs(x,v);
    }
}
void solve(){
    cin >> n;
    nums.assign(n, -1);
    nw.assign(n,-1);
    g.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int j = 0; j < m; ++j) {
        cin >> p[j];
    }
    if(m < n-1){
        for (int i = 0; i < n - m-1; ++i) {
            p.push_back(1);
        }
    }
    sort(p.begin(),p.end());
    if(m > n-1){
        for (int i = 0; i < m - n+1; ++i) {
            int k = p.back();
            p.pop_back();
            p.back() *= k;
            p.back() %= mod;
        }
    }
    makenw(0, -1);
    dfs(0, -1);
    nums[0] = -1;
    sort(nums.begin(),nums.end());
    int res = 0;
    for (int i = 1; i < n; ++i) {
        res += nums[i] % mod * p[i-1];
        res %= mod;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
        g.clear();
        nums.clear();
        nw.clear();
    }
}