#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const int MOD = 998244353;

int n, m;
int s[N], t[N];
ll fact[N], inv_fact[N], cnt[N];

struct Fenwick{
    ll a[N];

    void update(ll i, ll v){
        for(; i < N; i += i & -i)
            a[i] += v;
    }

    ll query(ll i){
        ll ans = 0;
        for(; i >= 1; i -= i & -i)
            ans += a[i];
        return ans;
    }
} f;

ll fast_pow(ll base, ll exp){
    if(!exp) return 1ll;
    if(exp & 1) return base * fast_pow(base, exp - 1) % MOD;
    ll t = fast_pow(base, exp >> 1);
    return t * t % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        ++cnt[s[i]];
    }
    for(int i = 0; i < m; ++i){
        cin >> t[i];
    }

    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[N - 1] = fast_pow(fact[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

    ll curr = 1;
    curr *= fact[n];
    for(int i = 0; i < N; ++i)
        curr = curr * inv_fact[cnt[i]] % MOD;

    for(int i = 0; i < N; ++i)
        if(cnt[i])
            f.update(i, cnt[i]);

    // if fully equal?
    ll ans = 0;
    for(int i = 0; i < min(n, m); ++i){
        curr = curr * inv_fact[n - i] % MOD;
        curr = curr * fact[n - i - 1] % MOD;
        ans = (ans +curr * f.query(t[i] - 1)) % MOD;
        //cout << curr * f.query(t[i] - 1) << endl;

        if(!cnt[t[i]]) break;

        --cnt[t[i]];
        f.update(t[i], -1);
        if(i == n - 1 && n < m) ans = (ans + 1) % MOD;
        curr = curr * fact[cnt[t[i]] + 1] % MOD * inv_fact[cnt[t[i]]] % MOD;
    }

    cout << ans << "\n";
}