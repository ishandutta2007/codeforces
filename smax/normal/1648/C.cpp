#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;

long long power(long long a, long long b) {
    long long ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(200005), t(m);
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        cnt[s]++;
    }
    for (int i=0; i<m; i++)
        cin >> t[i];
    
    vector<long long> fact(n + 1), inv(n + 1);
    fact[0] = inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = power(fact[i], MOD - 2);
    }
    
    unordered_map<int, ordered_set<int>> mp;
    long long tot = 1;
    for (int i=1; i<=200000; i++)
        if (cnt[i] > 0) {
            mp[cnt[i]].insert(i);
            tot = tot * inv[cnt[i]] % MOD;
        }
    
    int ret = 0;
    bool ok = n < m;
    for (int i=0; i<m; i++) {
        if (i >= n)
            break;
        for (const auto &p : mp) {
            // cerr << "cnt: " << p.first << ", " << p.second.order_of_key(t[i]) << "\n";
            ret += tot * fact[p.first] % MOD * inv[p.first-1] % MOD * fact[n-i-1] % MOD * p.second.order_of_key(t[i]) % MOD;
            if (ret >= MOD)
                ret -= MOD;
        }
        // cerr << i << ",,, " << ret << "\n";
        if (cnt[t[i]] == 0) {
            ok = false;
            break;
        }
        mp[cnt[t[i]]].erase(t[i]);
        if (mp[cnt[t[i]]].empty())
            mp.erase(cnt[t[i]]);
        cnt[t[i]]--;
        if (cnt[t[i]] > 0)
            mp[cnt[t[i]]].insert(t[i]);
        tot = tot * fact[cnt[t[i]]+1] % MOD * inv[cnt[t[i]]] % MOD;
    }
    if (ok) {
        ret++;
        if (ret == MOD)
            ret = 0;
    }
    cout << ret << "\n";
    
    return 0;
}