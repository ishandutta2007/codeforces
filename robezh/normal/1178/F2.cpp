#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;
const ll mod = 998244353;

int n, m;
int a[N];
ll dp[N][N];
int mnl[N][N], mnr[N][N];
int bad[N][N];
int lt[N], rt[N];
int con[N];

void add(ll &to, ll val) {
    to += val;
    if(to >= mod) to -= mod;
}

ll get(int l, int r) {
    if(l >= r) return !bad[l][r];
    if(bad[l][r]) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll res1 = 0, res2 = 0;
    for(int lb = l; lb <= mnl[l][r]; lb++) {
        add(res1, get(l, lb - 1) * get(lb, mnl[l][r] - 1) % mod);
    }
    for(int rb = mnr[l][r]; rb <= r; rb++) {
        add(res2, get(mnr[l][r] + 1, rb) * get(rb + 1, r) % mod);
    }
    int mn = a[mnl[l][r]];
    int cur_r = mnl[l][r];
    ll res = res1 * res2 % mod;
    while(cur_r < mnr[l][r]) {
        if(a[cur_r] == mn) {
            cur_r++;
        }
        else {
            int nr = cur_r;
            while(nr < mnr[l][r] && a[nr] > mn) nr++;
            res *= get(cur_r, nr - 1);
            res %= mod;
            cur_r = nr;
        }
    }
    return dp[l][r] = res;
}

int main(){
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    int nn = 0;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(nn == 0 || a[nn - 1] != x) {
            a[nn++] = x;
            if(nn > 2 * n + 1) return cout << 0 << endl, 0;
        }
    }

    m = nn;
//    for(int i = 0; i < m; i++) cout << a[i] << " ";
//    cout << endl;
    for(int i = 1; i <= n; i++) {
        int l = N, r = -1;
        for(int j = 0; j < m; j++) {
            if(a[j] == i) {
                l = min(l, j), r = max(r, j);

            }
        }

        for(int j = l; j <= r; j++) {
            if(a[j] < i) return cout << 0 << endl, 0;
        }
        lt[i] = l, rt[i] = r;
    }
//    for(int i = 0; i < m; i++) cout << con[i] << " ";
//    cout << endl;
    for(int l = 0; l < m; l++) {
        for(int r = l; r < m; r++) {
            mnl[l][r] = l;
            for(int i = l; i <= r; i++) {
                if(a[i] < a[mnl[l][r]]) mnl[l][r] = i;
                if(lt[a[i]] < l || rt[a[i]] > r) bad[l][r] = 1;
            }
            mnr[l][r] = r;
            for(int i = r; i >= l; i--) {
                if(a[i] < a[mnr[l][r]]) mnr[l][r] = i;
            }
        }
    }
    cout << (get(0, m - 1) % mod + mod) % mod << endl;

}