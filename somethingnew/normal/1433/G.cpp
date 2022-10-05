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
vector<pair<int,int>> r;
vector<vector<pair<int,int>>> g;
bool comp(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}
void addto(vector<pair<int,int>> &prc, int v, int p){
    for(auto i : g[v]){
        prc.emplace_back(i.second + p, i.first);
        push_heap(prc.begin(), prc.end(),comp);
    }
}
vector<int> to(int p){
    vector<int> to(g.size(), -1);
    to[p] = 0;
    vector<pair<int,int>> price;
    addto(price, p, 0);
    while(!price.empty()){
        if(to[price[0].second] == -1){
            int a = price[0].second;
            int b = price[0].first;
            to[a] = b;
            pop_heap(price.begin(), price.end(), comp);
            price.pop_back();
            addto(price, a, b);
        }else{
            pop_heap(price.begin(), price.end(), comp);
            price.pop_back();
        }
    }
    return to;
}
vector<int> solve(pair<int,int> kr){
    int s = kr.first;
    int f = kr.second;
    vector<int> sto = to(s);
    vector<int> fto = to(f);
    vector<int> ans(r.size(), 0);
    for (int i = 0; i < r.size(); ++i) {
        int a = r[i].first;
        int b = r[i].second;
        //if(i == 3){
        //    cout << s << ' ' << f << ' ' << sto[f] << ' ' << sto[a] << ' ' <<  fto[b] << ' ' << fto[a] + sto[b] << endl;
        //}
        ans[i] = min(sto[f], min(sto[a] + fto[b], fto[a] + sto[b]));
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    g.assign(n, {});
    r.assign(m, {0,0});
    for (auto &i : r) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        i = {a, b};
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    vector<pair<int,int>> kur(k, {0, 0});
    for (auto & i : kur) {
        cin >> i.first >> i.second;
        i.first--;i.second--;
    }
    vector<int> ans(m, 0);
    for (int i = 0; i < k; ++i) {
        vector<int> sa = solve(kur[i]);
        for (int j = 0; j < m; ++j) {
            ans[j] += sa[j];
        }
    }
    int mn = ans[0];
    for (int i = 0; i < m; ++i) {
        mn = min(mn, ans[i]);
    }
    cout << mn;
}