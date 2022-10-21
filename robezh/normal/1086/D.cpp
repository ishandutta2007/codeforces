#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;
typedef pair<int, int> P;

set<int> S[3];
int num[128];
int n,q;
int x[N];
vector<P> itv;

struct BIT{
    int bit[N];

    void add(int x, int val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} bit[3];

void make_itv(int l, int r){
    if(l <= r) itv.emplace_back(l, r);
}

void merge_itv() {
    if(itv.size() < 2) return ;
    if(itv[0].first > itv[1].first) swap(itv[0], itv[1]);
    if(itv[0].second >= itv[1].first) {
        int l = itv[0].first, r = max(itv[1].second, itv[0].second);
        itv.clear();
        itv.push_back({l, r});
    }
}

int get_cur_res(){
    int res = 0;
    for(int k = 0; k < 3; k++) {
        itv.clear();
        int m = (k + 2) % 3, s = (k + 1) % 3;
        int l = S[m].empty() ? 0 : *(--S[m].end());
        int r = S[s].empty() ? -1 : *(--S[s].end());
        make_itv(l, r);
        l = S[s].empty() ? n : *(S[s].begin());
        r = S[m].empty() ? n - 1: *(S[m].begin());
        make_itv(l, r);
        merge_itv();
        res += bit[k].get(n-1);
        for(auto &p : itv){
            res -= bit[k].get(p.first, p.second);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    num['P'] = 2, num['R'] = 1, num['S'] = 0;

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        x[i] = num[c];
        bit[x[i]].add(i, 1);
        S[x[i]].insert(i);
    }
    cout << get_cur_res() << "\n";
    while(q--) {
        int i, a; char c;
        cin >> i >> c;
        i--; a = num[c];
        bit[x[i]].add(i, -1);
        S[x[i]].erase(i);
        x[i] = a;
        bit[x[i]].add(i, 1);
        S[x[i]].insert(i);
        cout << get_cur_res() << "\n";
    }


}