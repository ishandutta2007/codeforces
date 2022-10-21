#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)1e5 + 50, mod = (int)1e9 + 9;

map<P, int> mp;
int up[N], down[N];
set<int> up_to[N], down_to[N];
int x[N], y[N];
int sup[N];
set<int> S;

int n;
ll res = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        mp[{x[i], y[i]}] = i;
    }
    for(int i = 0; i < n; i++) {
        for(int d = -1; d <= 1; d++) {
            auto it = mp.find({x[i] + d, y[i] + 1});
            if(it != mp.end()) {
                up_to[i].insert(it->second);
                up[i] ++;
                down_to[it->second].insert(i);
                down[it->second]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(down[i] == 1) {
            sup[*down_to[i].begin()] ++;
        }
    }
    for(int i = 0; i < n; i++) if(sup[i] == 0) S.insert(i);

    for(int i = 0; i < n; i++) {
        res *= n; res %= mod;
        int cur = i % 2 == 0 ? *S.rbegin() : *S.begin();
        S.erase(cur);
        res += cur; res %= mod;

        for(int u : up_to[cur]) {
            down[u]--;
            down_to[u].erase(cur);
            if(down[u] == 1) {
                int dw = *down_to[u].begin();
                sup[*down_to[u].begin()]++;
                S.erase(dw);
            }
        }
        if(down[cur] == 1) {
            int dw = *down_to[cur].begin();
            sup[dw]--;
            if(sup[dw] == 0) S.insert(dw);
        }
        for(int d : down_to[cur]) {
            up[d]--;
            up_to[d].erase(cur);
            if(up[d] == 0) {
                S.insert(d);
            }
        }

    }
    cout << res << endl;

}