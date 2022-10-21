#include <bits/stdc++.h>
using namespace std;
const int K = 19, M = (1 << 18) + 5;
typedef long long ll;

int n;
int cnt[M];
ll g[K][M];
ll dp[M][K];
string str[K];
ll res[M];
vector<ll> d[M];
ll a[M];
vector<int> ps;
vector<int> parts[1000];
int sz = 0;

void part(int take, int rem) {
    ps.push_back(take);
    if(rem == 0) {
        parts[sz++] = ps;
    } else {
        for(int nxt = take; nxt <= rem; nxt++) {
            part(nxt, rem - nxt);
        }
    }
    ps.pop_back();
}

void solve(int p) {
    vector<int> nps = parts[p];
    for(int i = 0; i < (1 << n); i++) a[i] = 1;
    for(int x : nps) for(int i = 0; i < (1 << n); i++) a[i] *= g[x][i];
    ll curres = 0;
    for(int i = 0; i < (1 << n); i++) {
        int s = (cnt[i] % 2 == n % 2 ? 1 : -1);
        curres += s * a[i];
    }
    do {
        int mask = 0;
        for(int x : nps) {
            mask *= 2;
            mask <<= (x - 1);
            mask |= ((1 << (x - 1)) - 1);
        }
        res[mask] += curres;
    } while(next_permutation(nps.begin(), nps.end()));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
    for(int i = 0; i < (1 << n); i++) cnt[i] = __builtin_popcount(i);
    for(int i = 0; i < n; i++) dp[(1 << i)][i] = 1;
    for(int i = 1; i < (1 << n); i++) {
        for(int cur = 0; cur < n; cur++) {
            if(!(i >> cur & 1)) continue;
            for(int nxt = 0; nxt < n; nxt++) {
                if((i >> nxt & 1) || str[cur][nxt] == '0') continue;
                dp[i ^ (1 << nxt)][nxt] += dp[i][cur];
            }
        }
    }
    g[0][0] = 1;
    for(int i = 1; i < (1 << n); i++) {
        int c = cnt[i];
        for(int cur = 0; cur < n; cur++) {
            if(i >> cur & 1) g[c][i] += dp[i][cur];
        }
    }
    for(int len = 0; len < n; len++) {
        for(int b = 0; b < n; b++) {
            for(int mask = 0; mask < (1 << n); mask++) {
                if(mask >> b & 1) g[len][mask] += g[len][mask ^ (1 << b)];
            }
        }
    }
    for(int i = 0; i < (1 << n); i++) d[i].push_back(1);

    for(int i = 1; i <= n; i++) part(i, n - i);
    for(int i = 0; i < sz; i++) solve(i);

    for(int b = 0; b < (n - 1); b++) {
        for(int mask = 0; mask < (1 << (n - 1)); mask++) {
            if(!(mask >> b & 1)) res[mask] -= res[mask ^ (1 << (b))];
        }
    }
    for(int i = 0; i < (1 << (n - 1)); i++) cout << res[i] << " ";
    cout << '\n';
}