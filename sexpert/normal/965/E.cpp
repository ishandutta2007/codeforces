#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int h[MAXN], to[MAXN][26], isw[MAXN], sz[MAXN], lst;
multiset<int> pos[MAXN];

void add(string s) {
    int cur = 0, ch = 0;
    for(auto c : s) {
        int d = c - 'a';
        if(!to[cur][d]) {
            to[cur][d] = ++lst;
            h[lst] = ch + 1;
        }
        cur = to[cur][d];
        ch++;
    }
    isw[cur] = 1;
}

void dfs(int s) {
    sz[s] = 1;
    int ms = 0, mv = 0;
    for(int i = 0; i < 26; i++) {
        if(!to[s][i])
            continue;
        dfs(to[s][i]);
        sz[s] += sz[to[s][i]];
        if(sz[to[s][i]] > ms) {
            ms = sz[to[s][i]];
            mv = i;
        }
    }
    if(ms == 0) {
        if(isw[s])
            pos[s].insert(-h[s]);
        return;
    }
    swap(pos[s], pos[to[s][mv]]);
    for(int i = 0; i < 26; i++) {
        if(!to[s][i] || i == mv)
            continue;
        for(auto x : pos[to[s][i]])
            pos[s].insert(x);
        pos[to[s][i]].clear();
    }
    if(isw[s])
        pos[s].insert(-h[s]);
    else {
        if(s == 0)
            return;
        pos[s].erase(pos[s].begin());
        pos[s].insert(-h[s]);
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        add(s);
    }
    dfs(0);
    long long ans = 0;
    for(auto x : pos[0])
        ans -= x;
    cout << ans << '\n';
}