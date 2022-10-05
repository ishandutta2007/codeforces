//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
vector<vector<int>> g;
vector<int> vals;
struct smartmap{
    map<int, int> mp;
    int toxor = 0;
    void add(int x) {
        mp[x ^ toxor] = 1;
    }
    void operator ^=(int x) {
        toxor ^= x;
    }
    int find(int x){
        return mp[x ^ toxor];
    }
    int size() {
        return mp.size();
    }
};
bool merge(smartmap &a, smartmap &b, int t) {
    if (a.size() > b.size())
        swap(a, b);
    bool nok = 0;
    for (auto i : a.mp) {
        if (i.second == 1)
        if (b.find(i.first ^ a.toxor ^ t))
            nok = 1;
    }
    for (auto i : a.mp) {
        if (i.second)
            b.add(i.first ^ a.toxor);
    }
    return nok;
}
int res = 0;
smartmap dfsde(int v, int p) {
    smartmap mp;
    mp.add(0);
    int bd = 0;
    for (auto i : g[v]) {
        if (i != p) {
            auto q = dfsde(i, v);
            bd |= merge(q, mp, vals[v]);
        }
    }
    if (bd) {
        res++;
        mp.mp.clear();
        return mp;
    }
    mp ^= vals[v];
    return mp;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vals.assign(n, {});
    g.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfsde(0, 0);
    cout << res << '\n';
}