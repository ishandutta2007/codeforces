#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 4e5 + 3;
const int MOD = 998244353;
const int LOGN = 19;

int n, m, x[N], y[N];
int f[N], inv_f[N];

struct Fenwick{
    int a[N];

    void update(int i, int v){
        for(; i < N; i += i&-i)
            a[i] += v;
    }
    int query(int i){
        int ret = 0;
        for(; i >= 1; i -= i&-i)
            ret += a[i];
        return ret;
    }
    int find_kth(int k){
        int sum = 0, idx = 0;
        for(int i = LOGN - 1; i >= 0; --i){
            if(sum + a[idx + (1 << i)] < k){
                idx += 1 << i;
                sum += a[idx];
            }
        }
        return idx + 1;
    }
} fenwick;

int fast_pow(int base, int exp){
    if(!exp) return 1;
    if(exp & 1) return (ll)base * fast_pow(base, exp ^ 1) % MOD;
    int t = fast_pow(base, exp >> 1);
    return (ll)t * t % MOD;
}

int comb(int n, int k){
    return (ll)f[n] * inv_f[k] % MOD * inv_f[n - k] % MOD;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> x[i] >> y[i];

    vector<int> v, rem;
    for(int i = m - 1; i >= 0; --i){
        int p = fenwick.find_kth(y[i]);
        int q = fenwick.find_kth(y[i] + 1);
        v.push_back(q);
        fenwick.update(p, -1);
        rem.push_back(p);
    }

    for(int p: rem)
        fenwick.update(p, 1);

    sort(v.begin(), v.end());
    if(!v.empty() && v.back() == n + 1) v.pop_back();
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << comb(2 * n - v.size() - 1, n) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = (ll)f[i - 1] * i % MOD;

    inv_f[N -  1] = fast_pow(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; --i)
        inv_f[i] = (ll)inv_f[i + 1] * (i + 1) % MOD;

    for(int i = 1; i < N; ++i)
        fenwick.update(i, 1);

    int t;
    cin >> t;

    while(t--) solve();
}