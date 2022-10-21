#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n;
set<int> G[N];
set<int> len[N];
queue<int> que;
int cnt;
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cnt = n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].insert(b), G[b].insert(a);
    }
    for(int i = 0; i < n; i++) if(G[i].size() == 1) {
        que.push(i);
        len[i].insert(0);
    }
    while(!que.empty() && cnt > 1) {
        int v = que.front(); que.pop();
        if(len[v].size() > 1) continue;
        vis[v] = true;
        cnt--;
        int nxt = *G[v].begin();
        len[nxt].insert(*len[v].begin() + 1);
        G[nxt].erase(v);
        if(G[nxt].size() == 1) que.push(nxt);
    }


    if(cnt != 1) return cout << "-1" << endl, 0;
    int fin = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) { fin = i; break;}
    }
    int rs_cnt = 0;
    int res = 0;
    for(auto x : len[fin]) {
        if(x != 0) rs_cnt++;
        res += x;
    }
    if(rs_cnt > 2) return cout << "-1" << endl, 0;

    while(res % 2 == 0) res /= 2;
    cout << res << endl;
}