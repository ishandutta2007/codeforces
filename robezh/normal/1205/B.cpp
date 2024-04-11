#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const int INF = (int)1e9;

int n, tn;
ll a[N];
vector<int> G[N];
int dis[N], pv[N];

int bfs(int s) {
    int res = INF;
    queue<int> que;
    fill(dis, dis + n, INF);
    dis[s] = 0;
    pv[s] = -1;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int nxt : G[v]) {
            if(dis[nxt] != INF) {
                if(nxt != pv[v]) res = min(res, dis[nxt] + dis[v] + 1);
            }
            else {
                dis[nxt] = dis[v] + 1;
                pv[nxt] = v;
                que.push(nxt);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(x > 0) a[tn++] = x;
    }
    n = tn;
    if(n > 200) return cout << "3" << endl, 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] & a[j]) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    int res = INF;
    for(int i = 0; i < n; i++) {
        res = min(res, bfs(i));
    }
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
}