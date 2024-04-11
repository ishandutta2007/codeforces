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
#define all(x) (x).begin(), (x).end()

using namespace std;
vector<vector<int>> g;
vector<vector<int>> ketr;
vector<pair<int, int>> inout;
int t;
void ketrdfs(int v, int p) {
    inout[v].first = t;
    t++;
    for (auto i : ketr[v]){
        if (i == p)
            continue;
        ketrdfs(i, v);
    }
    inout[v].second = t;
    t++;
}
vector<pair<int, int>> era;
set<pair<int, int>> st;
int res;
void dfssolv(int v, int p){
    auto i = st.lower_bound(inout[v]);
    if (st.size() != 0 and i != st.begin()) {
        --i;
        if (i->first <= inout[v].first and i->second >= inout[v].second) {
            era[v] = *i;
           // cout << "ER " << i->first << ' ' << i->second << endl;
            st.erase(i);
        }
    }
    st.insert(inout[v]);
  //  cout << "ADD " << inout[v].first << ' ' << inout[v].second << endl;
    res = max(res, (int)st.size());
    for (auto q : g[v]) {
        if (q == p)
            continue;
        dfssolv(q, v);
    }
    if (era[v].first != -1)
        st.insert(era[v]);
    st.erase(inout[v]);
}
void solve(){
    int n;
    res = 1;
    st.clear();
    cin >> n;
    era.assign(n, {-1, -1});
    g.assign(n, {});
    ketr.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> b;
        b--;
        g[b].push_back(i);
        g[i].push_back(b);
    }
    for (int i = 1; i < n; ++i) {
        int b;
        cin >> b;
        b--;
        ketr[b].push_back(i);
        ketr[i].push_back(b);
    }
    inout.assign(n, {});
    t = 0;
    ketrdfs(0, -1);
    dfssolv(0, -1);
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}