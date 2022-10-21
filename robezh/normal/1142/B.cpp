#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, LOGN = 18, INF = (int)1e9;

struct query{
    int r, id;
};

int n, m, q;
int per[N], num[N];
int to[N];
vector<query> qry[N];
int res[N], val[N];
int nxt[LOGN][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) cin >> per[i], per[i]--, to[per[i]] = i;
    for(int i = 0; i < m; i++) {
        cin >> num[i];
        num[i]--;
        num[i] = to[num[i]];
    }
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qry[l].push_back({r, i});
    }
    for(int i = 0; i < n; i++) val[i] = -1;
    for(int i = m - 1; i >= 0; i--) {
        nxt[0][i] = val[(num[i]+1)%n];
        val[num[i]] = i;
    }
    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j < m; j++) {
            int nx = nxt[i-1][j];
            nxt[i][j] = (nx == -1 ? -1 : nxt[i-1][nx]);
        }
    }
    int mn = INF;
    for(int i = m - 1; i >= 0; i--) {
        int cur = i;
        for(int j = 0; j < LOGN; j++) {
            if((((n - 1) >> j) & 1) && cur != -1) cur = nxt[j][cur];
        }
        if(cur != -1) mn = min(mn, cur);
        for(const auto &p : qry[i]) {
            res[p.id] = (mn <= p.r);
        }
    }
    for(int i = 0; i < q; i++) cout << res[i];



}