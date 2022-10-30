
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

const ll MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n, m;
    cin >> n >> m;
    vll s(n), fs(m), hs(m);
    for (ll i = 0; i < n; ++i){
        cin >> s[i];
        --s[i];
    }
    vvll fcs(n);
    for (ll i = 0; i < m; ++i){
        ll f, h;
        cin >> f >> h;
        --f;
        fcs[f].push_back(h);
    }
    for (ll i = 0; i < n; ++i) sort(fcs[i].begin(), fcs[i].end());
    vll fc(n), fi(n);
    vll left_end_counts(n);
    for (ll i = 0; i < n; ++i){
        ++fc[s[i]];
        while (fi[s[i]] < fcs[s[i]].size() && fcs[s[i]][fi[s[i]]] == fc[s[i]]){
            ++left_end_counts[i];
            ++fi[s[i]];
        }
    }
    fc.assign(n, 0); fi.assign(n, 0);
    vll right_end_counts(n);
    for (ll i = n - 1; i >= 0; --i){
        ++fc[s[i]];
        while (fi[s[i]] < fcs[s[i]].size() && fcs[s[i]][fi[s[i]]] == fc[s[i]]){
            ++right_end_counts[i];
            ++fi[s[i]];
        }
    }
    vll right_counts(n);
    for (ll i = 0; i < n; ++i) right_counts[s[i]] += right_end_counts[i];
    ll best = 0, ways = 1;
    for (ll i = 0; i < n; ++i) if (right_counts[i] > 0){
        ++best;
        ways = (ways * right_counts[i]) % MOD;
    }
    vll left_counts(n);
    for (ll index = 0; index < n; ++index){
        right_counts[s[index]] -= right_end_counts[index];
        if (left_end_counts[index] > 0){
            left_counts[s[index]] += left_end_counts[index];
            ll score = 1, this_ways = left_end_counts[index];
            for (ll i = 0; i < n; ++i) if (i != s[index]){
                if (left_counts[i] > 0 || right_counts[i] > 0){
                    ++score;
                    if (left_counts[i] > 0 && right_counts[i] > 0){
                        if (left_counts[i] > 1 || right_counts[i] > 1){
                            ++score;
                            this_ways = (((this_ways * min<ll>(left_counts[i], right_counts[i])) % MOD) * (max<ll>(left_counts[i], right_counts[i]) - 1)) % MOD;
                        }
                        else this_ways = (this_ways * 2) % MOD;
                    }
                    else{
                        this_ways = (this_ways * max<ll>(left_counts[i], right_counts[i])) % MOD;
                    }
                }
            }
            if (right_counts[s[index]] > 0 && (right_counts[s[index]] > 1 || left_counts[s[index]] > 1)){
                ++score;
                if (right_counts[s[index]] >= left_counts[s[index]]) this_ways = (this_ways * (right_counts[s[index]] - 1)) % MOD;
                else this_ways = (this_ways * right_counts[s[index]]) % MOD;
            }
            if (score > best){
                best = score;
                ways = this_ways;
            }
            else if (score == best) ways = (ways + this_ways) % MOD;
        }
    }
    cout << best << ' ' << ways << endl;
    return 0;
}