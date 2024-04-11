#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
typedef pair<int, int> pii;

struct P {
    int n, win, a, b;
};

int dp[6][6][205][205];
P nxt[6][6][205][205];
int cnt[2];
vector<pii> ss;

int get(int n, int win, int a, int b) {
    if(a < 0 || b < 0) return -INF;
    if(dp[n][win][a][b] != -5) return dp[n][win][a][b];
    int &ans = dp[n][win][a][b];
    ans = -INF;

    if(win == 3 || n - win == 3) {
        if(a != 0 || b != 0) return -INF;
        ans = (win - (n - win));
        nxt[n][win][a][b].n = -1;
        return ans;
    }
    int mx = (n < 4 ? 25 : 15);
    for(int b2 = 0; b2 <= mx - 2; b2++) {
        int nxt_val = get(n + 1, win + 1, a - mx, b - b2);
        if(nxt_val > ans) {
            nxt[n][win][a][b] = {n + 1, win + 1, a - mx, b - b2};
            ans = nxt_val;
        }
    }
    for(int a2 = mx + 1; a2 <= a; a2++) {
        int nxt_val = get(n + 1, win + 1, a - a2, b - (a2 - 2));
        if(nxt_val > ans) {
            nxt[n][win][a][b] = {n + 1, win + 1, a - a2, b - (a2 - 2)};
            ans = nxt_val;
        }
    }
    for(int a2 = 0; a2 <= mx - 2; a2++) {
        int nxt_val = get(n + 1, win, a - a2, b - mx);
        if(nxt_val > ans) {
            nxt[n][win][a][b] = {n + 1, win, a - a2, b - mx};
            ans = nxt_val;
        }
    }
    for(int b2 = mx + 1; b2 <= b; b2++) {
        int nxt_val = get(n + 1, win, a - (b2 - 2), b - b2);
        if(nxt_val > ans) {
            nxt[n][win][a][b] = {n + 1, win, a - (b2 - 2), b - b2};
            ans = nxt_val;
        }
    }
    return ans;
}

void trace(int n, int win, int a, int b) {
    P &nx = nxt[n][win][a][b];
    if(nx.n == -1) return ;
    if(a - nx.a > b - nx.b) cnt[0]++;
    else cnt[1]++;
    ss.push_back({a - nx.a, b - nx.b});
    trace(nx.n, nx.win, nx.a, nx.b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            for(int a = 0; a < 205; a++) fill(dp[i][j][a], dp[i][j][a] + 205, -5);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        int ans = get(0, 0, a, b);
        if(ans == -INF) {
            cout << "Impossible\n";
            continue;
        }
        cnt[0] = cnt[1] = 0;
        ss.clear();
        trace(0, 0, a, b);
        cout << cnt[0] << ":" << cnt[1] << '\n';
        for(auto p : ss) {
            a -= p.first, b -= p.second;
            cout << p.first << ":" << p.second << ' ';
        }
        assert(a == 0 && b == 0);
        cout << '\n';
    }
}