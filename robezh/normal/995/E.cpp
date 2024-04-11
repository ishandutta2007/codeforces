#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mod;
typedef pair<int, int> P;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int inv(int x) {
    return int(fp(x, mod - 2));
}

map<int, P> pv;
int s, t;

struct node{
    int v, tp;
};

int main() {
    cin >> s >> t >> mod;
    queue<node> que;
    que.push({s, 0});
    que.push({t, 1});
    int l, r;
    while(true) {
        auto nd = que.front(); que.pop();
        int v = nd.v, tp = nd.tp;
        vector<int> ck = {(v + 1) % mod, (v - 1 + mod) % mod, inv(v)};
        bool found = false;
        for(int x : ck) {
            if(pv.count(x)) {
                if(pv[x].second == tp) continue;
                found = true;
                l = tp ? x : v;
                r = tp ? v : x;
            }
            else {
                pv[x] = {v, tp};
                que.push({x, tp});
            }
            if(found) break;
        }
        if(found) break;
    }
    vector<int> path;
    int cur = l;
    while(true) {
        path.push_back(cur);
        if(cur == s) break;
        cur = pv[cur].first;
    }
    reverse(path.begin(), path.end());
    cur = r;
    while(true) {
        path.push_back(cur);
        if(cur == t) break;
        cur = pv[cur].first;

    }
    vector<int> res;
    for(int i = 0; i + 1 < path.size(); i++) {
        int x = path[i], y = path[i+1];
        if((x + 1) % mod == y) res.push_back(1);
        else if((x + mod - 1) % mod == y) res.push_back(2);
        else res.push_back(3);
    }
    cout << res.size() << endl;
    for(int x : res) cout << x << " ";

}