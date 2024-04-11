#include "list"
#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;
struct otrtr{
    int sz;
    vector<long long> tree;
    long long func(long long a, long long b){
        return a + b;
    }
    void make(int n){
        sz = 1;
        while(sz < n){
            sz *= 2;
        }
        tree.assign(sz * 2 + 10, 0);
        for (int i = 0; i < sz; ++i) {
            tree[sz+i] = 0;
        }
        for (int j = sz-1; j > 0; --j) {
            tree[j] = func(tree[j * 2], tree[j * 2 + 1]);
        }
    }
    long long sum(int l, int r){
        int ll = sz + l;
        int rr = sz + r;
        long long res = 0;
        while(ll < rr){
            if(ll&1)
                res = func(res, tree[ll++]);
            if(!(rr&1))
                res = func(res, tree[rr--]);
            ll /= 2;
            rr /= 2;
        }
        if(ll == rr){
            res = func(res, tree[ll]);
        }
        return res;
    }
    void change(int pos, long long x){
        pos += sz;
        tree[pos] = x;
        while(pos != 1){
            tree[pos/2] = func(tree[pos], tree[pos^1]);
            pos /= 2;
        }
    }
};
long long solve1(otrtr &x, vector<pair<int,int>> xinf, vector<pair<int,pair<int,int>>> yinf){
    long long res = 0;
    for (auto & elem : yinf) {
        if(xinf.empty())
            return res;
        while(xinf.back().first < elem.first){
            x.change(xinf.back().second, 0);
            xinf.pop_back();
            if(xinf.empty())
                return res;
        }
        res += x.sum(elem.second.first, elem.second.second);
    }
    return res;
}
long long solve2(otrtr &x, vector<pair<int,int>> xinf, vector<pair<int,pair<int,int>>> yinf){
    long long res = 0;
    for (auto & elem : yinf) {
        if(xinf.empty())
            return res;
        while(xinf.back().first > elem.first){
            x.change(xinf.back().second, 0);
            xinf.pop_back();
            if(xinf.empty())
                return res;
        }
        res += x.sum(elem.second.first, elem.second.second);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    otrtr xl;
    otrtr xr;
    vector<pair<int,int>> xlinf;
    vector<pair<int,int>> xrinf;
    vector<pair<int,pair<int,int>>> yinf;
    xl.make(1000001);
    xr.make(1000001);
    int  doptoans = 1;
    for (int i = 0; i < n; ++i) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        if(lx == 0){
            xl.change(y, 1);
            xlinf.emplace_back(rx, y);
        }
        else if(rx == 1000000){
            xr.change(y, 1);
            xrinf.emplace_back(lx, y);
        }
        if(lx == 0 && rx == 1000000)
            doptoans++;
    }
    for (int i = 0; i < m; ++i) {
        int x,ly,ry;
        cin >> x >> ly >> ry;
        yinf.push_back({x, {ly, ry}});
        if(ly == 0 && ry == 1000000)
            doptoans++;
    }
    sort(yinf.begin(),yinf.end());
    sort(xlinf.rbegin(),xlinf.rend());
    sort(xrinf.begin(),xrinf.end());
    long long ans = solve1(xl, xlinf, yinf);
    sort(yinf.rbegin(),yinf.rend());
    ans += solve2(xr, xrinf, yinf);
    cout << ans + doptoans << endl;
}