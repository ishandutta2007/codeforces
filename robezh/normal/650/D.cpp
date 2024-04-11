#include <bits/stdc++.h>
using namespace std;

const int N = (int)4e5 + 50, INF = (int)1e9 + 50;

struct Pu {
    int val, idx;
};

int n, m, h[N];
int a[N][2], b[N][2];
int lis = 0;
vector<Pu> U[N];
int dp[N];
int uni[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < m; i++) {
        int k, b; cin >> k >> b; k--;
        U[k].push_back({b, i});
    }
    fill(dp, dp + N, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int loc = (int)(lower_bound(dp, dp + N, h[i]) - dp);
        a[i][0] = loc;
        for(auto p : U[i]) b[p.idx][0] = (int)(lower_bound(dp, dp + N, p.val) - dp);
        dp[loc] = h[i];
    }
    fill(dp, dp + N, INF);
    dp[0] = -INF;
    for(int i = n - 1; i >= 0; i--) {
        int loc = (int)(lower_bound(dp, dp + N, -h[i]) - dp);
        a[i][1] = loc;
        for(auto p : U[i]) b[p.idx][1] = (int)(lower_bound(dp, dp + N, -p.val) - dp);
        dp[loc] = -h[i];
    }

    lis = (int)(lower_bound(dp, dp + N, INF) - dp) - 1;
//    for(int i = 0; i < n; i++) cout << i << ": in lis: " <<(int)(a[i][0] + a[i][1] - 1 == lis) <<" " <<  a[i][0] << ", " << a[i][1] <<endl;

    fill(uni, uni + N, -1);
    for(int i = 0; i < n; i++) {
        if(a[i][0] + a[i][1] - 1 == lis) {
            if(uni[a[i][0]] == -1) uni[a[i][0]] = i;
            else uni[a[i][0]] = -INF;
        }
    }
    for(int i = 0; i < n; i++) {
        for(auto p : U[i]) {
            int curlis = b[p.idx][0] + b[p.idx][1] - 1;
            if(curlis >= lis) res[p.idx] = curlis;
            else {
                if(a[i][0] + a[i][1] - 1 == lis && uni[a[i][0]] != -INF) {
                    res[p.idx] = lis - 1;
                }
                else {
                    res[p.idx] = lis;
                }
            }
        }
    }
    for(int j = 0; j < m; j++) cout << res[j] << "\n";
}