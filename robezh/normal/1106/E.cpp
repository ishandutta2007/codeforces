#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll INF = (ll)1e18;

int n,m,k;
int s[N], t[N], d[N], w[N];
ll dp[2][N];
int nxt[N], gn[N];
vector<int> in[N], out[N];

struct cmp{
    bool operator ()(const int &i1, const int &i2) {
        if(w[i1] == w[i2]) {
            if(d[i1] == d[i2]) return i1 < i2;
            return d[i1] > d[i2];
        }
        return w[i1] > w[i2];
    }
};

set<int, cmp> que;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> s[i] >> t[i] >> d[i] >> w[i];
        s[i] --, t[i] --; d[i] --;
    }
    for(int i = 0; i < k; i++) {
        in[s[i]].push_back(i);
        out[t[i] + 1].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        for(int v : in[i]) que.insert(v);
        for(int v : out[i]) que.erase(v);
        if(!que.empty()) {
            int id = *que.begin();
            nxt[i] = d[id] + 1;
            gn[i] = w[id];
        }
        else {
            nxt[i] = i + 1;
            gn[i] = 0;
        }

    }
//    for(int i = 0; i < n; i++) cout << nxt[i] << " ";
//    cout << endl;
//    for(int i = 0; i < n; i++) cout << gn[i] << " ";
//    cout << endl;
////

    ll res = INF;

    int la = 0, nw = 1;
    fill(dp[nw], dp[nw] + n, INF);
    dp[nw][n] = 0;
    for(int j = n-1; j >= 0; j--) dp[nw][j] = dp[nw][nxt[j]] + gn[j];
    res = min(res, dp[nw][0]);
    for(int i = 1; i <= m; i++) {
        swap(la, nw);
        fill(dp[nw], dp[nw] + n + 1, INF);
        for(int j = n - 1; j >= 0; j--) {
            dp[nw][j] = min(dp[la][j+1], dp[nw][nxt[j]] + gn[j]);
        }
        res = min(res, dp[nw][0]);
    }
    cout << res << endl;


}