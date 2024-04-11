#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50;
typedef long long ll;
const ll INF = (ll)1e18;
typedef pair<int, int> P;

int n;
ll k;
ll a[N];
int e[N];
int mm[N];
bool p[N];
ll vs[N];
int cnt[N];
vector<int> trans[N];
vector<P> upds;
ll prod[N];
ll dp[11 + 2][(1 << 11) + 5], nxt[11 + 2][(1 << 11) + 5];

vector<ll> get_primes(ll x) {
    vector<ll> res;
    for(int i = 2; i < N; i++) {
        if(p[i] && x % i == 0) {
            res.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res.push_back(x);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mm[0]=-1;
    for(int i = 1; i < N; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
    fill(p, p + N, true);
    for(int i = 2; i < N; i++) {
        if(!p[i]) continue;
        for(int j = i * 2; j < N; j += i) p[j] = false;
    }
    cin >> n >> k;
    ll agcd = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        agcd = __gcd(a[i], agcd);
    }
    for(int i = 0; i < n; i++) {
        cin >> e[i];
    }
    vector<ll> ds = get_primes(agcd);
    int plen = ds.size();
    assert(plen <= 11);
    for(int i = 0; i < n; i++) {
        ll b = 1;
        for(ll d : ds) {
            while(a[i] % d == 0) a[i] /= d, b *= d;
        }
        a[i] = b;
    }
    vector<int> idxs(n, 0);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [](int a, int b) {
        return e[a] < e[b];
    });
    map<ll, int> mp;
    vector<int> useful;
    for(int i : idxs) {
        int &c = mp[a[i]];
        if(c < plen) {
            c++;
            useful.push_back(i);
        }
    }
    for(int u : useful) {
        ll b = a[u];
        fill(vs, vs + plen, 1);
        for(int j = 0; j < plen; j++) {
            while(b % ds[j] == 0) b /= ds[j], vs[j] *= ds[j];
        }
        assert(b == 1);
        prod[0] = 1;
        for(int j = 1; j < (1 << plen); j++) {
            prod[j] = 1;
            for(int m = 0; m < plen; m++) {
                if((j >> m) & 1) prod[j] *= vs[m];
            }
            if(prod[j] <= k && cnt[j] < plen) {
                cnt[j]++;
                trans[u].push_back(j);
            }
        }
    }

    for(int i = 0; i <= plen; i++) {
        fill(dp[i], dp[i] + (1 << plen), INF);
        fill(nxt[i], nxt[i] + (1 << plen), INF);
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int mask : trans[i]) {
            int comp = ((1 << plen) - 1) ^ mask;
            for(int j = 0; j < plen; j++) {
                for(int sub = comp; ; sub = (sub - 1) & comp) {
                    if(dp[j][sub] != INF && nxt[j + 1][sub | mask] == INF) {
                        upds.push_back({j + 1, sub | mask});
                    }
                    nxt[j + 1][sub | mask] = min(nxt[j + 1][sub | mask], dp[j][sub] + e[i]);
                    if(sub == 0) break;
                }
            }
        }
        for(auto p : upds) {
            dp[p.first][p.second] = min(dp[p.first][p.second], nxt[p.first][p.second]);
            nxt[p.first][p.second] = INF;
        }
        upds.clear();
    }
    ll res = INF;
    for(int len = 0; len <= plen; len++) {
        if(dp[len][(1 << plen) - 1] == INF) continue;
        res = min(res, dp[len][(1 << plen) - 1] * len);
    }
    if(res == INF) res = -1;
    cout << res << '\n';

}