#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = (int)1e9;

struct node {
    int x[4];
    bool operator < (const node &o) const{
        for(int i = 0; i < 3; i++) {
            if(x[i] != o.x[i]) return x[i] < o.x[i];
        }
        return x[3] < o.x[3];
    }
};

int n = 4, m;
int a[5];
string str[4];
int la[4][N], oc[4];
map<node, int> dp;

node get_nxt(node nd, int i, int sz, int mx_j) {
    for(int j = i; j < i + sz; j++) {
        nd.x[j] = min(nd.x[j], max(0, mx_j - sz));
        nd.x[j] = la[j][nd.x[j]];
    }
    return nd;
}

int calc(node nd) {
    if(dp.count(nd)) return dp[nd];
    int mx = 0;
    for(int i = 1; i < 4; i++) if(nd.x[i] > nd.x[mx]) mx = i;
    if(nd.x[mx] == 0) return 0;
    int mx_j = nd.x[mx];
    int res = INF;
    for(int sz = 1; sz <= 4; sz++) {
        for(int i = 0; i + sz <= 4; i++) {
            if(i <= mx && mx < i + sz) res = min(res, calc(get_nxt(nd, i, sz, mx_j)) + a[sz]);
        }
    }
//    for(int j = 0; j < 4; j++) cout << nd.x[j] << " ";
//    cout << res << endl;
    return dp[nd] = res;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for(int i = 1; i <= 4; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> str[i], str[i] = " " + str[i];
    fill(oc, oc + 4, 0);
    for(int j = 1; j <= m; j++) {
        for(int i = 0; i < 4; i++) {
            if(str[i][j] == '*') oc[i] = j;
            la[i][j] = oc[i];
        }
    }
    node in;
    for(int i = 0; i < 4; i++) in.x[i] = la[i][m];
    cout << calc(in) << '\n';

}