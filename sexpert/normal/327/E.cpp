#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
map<int, ll> dp1[13], dp2[13];
map<pair<int,int>, ll> dp3[13][13], dp4[13][13];
map<pair<int, int>, int> to;
ll fac[25];

int main() {
    fac[0] = 1;
    for(int i = 1; i < 25; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    vector<ll> v1, v2;
    for(int i = 0; i < n/2; i++)
        v1.push_back(v[i]);
    for(int i = n/2; i < n; i++)
        v2.push_back(v[i]);
    int k, s1 = v1.size(), s2 = v2.size();

    for(int ms = 0; ms < (1 << s1); ms++) {
        ll su = 0;
        int co = 0;
        for(int i = 0; i < s1; i++) {
            if((ms >> i) & 1) {
                su += v1[i];
                co++;
            }
        }
        if(su < MOD)
            dp1[co][su]++;
        for(int sm = ms;;sm = (sm - 1) & ms) {
            ll su1 = 0, su2 = 0;
            int co1 = 0, co2 = 0;
            for(int i = 0; i < s1; i++) {
                if((ms >> i) & 1) {
                    if((sm >> i) & 1) {
                        co2++;
                        su2 += v1[i];
                    }
                    else {
                        co1++;
                        su1 += v1[i];
                    }
                }
            }
            if(su1 < MOD && su2 < MOD)
                dp3[co1][co2][{su1, su2}]++;
            if(sm == 0)
                break;
        }
    }

    int cur = 0;

    for(int ms = 0; ms < (1 << s2); ms++) {
        ll su = 0;
        int co = 0;
        for(int i = 0; i < s2; i++) {
            if((ms >> i) & 1) {
                su += v2[i];
                co++;
            }
        }
        if(su < MOD)
            dp2[co][su]++;
        for(int sm = ms;;sm = (sm - 1) & ms) {
            ll su1 = 0, su2 = 0;
            int co1 = 0, co2 = 0;
            for(int i = 0; i < s2; i++) {
                if((ms >> i) & 1) {
                    if((sm >> i) & 1) {
                        co2++;
                        su2 += v2[i];
                    }
                    else {
                        co1++;
                        su1 += v2[i];
                    }
                }
            }
            if(su1 < MOD && su2 < MOD) {
                if(!to.count({su1, su2}))
                    to[{su1,su2}] = cur++;
                dp4[co1][co2][{su1, su2}]++;
            }
            if(sm == 0)
                break;
        }
    }

    cin >> k;
    vector<ll> ks(k);
    for(auto &x : ks)
        cin >> x;
    sort(ks.begin(), ks.end());
    ll ans = fac[n];

    if(k >= 1) {
        for(auto x : ks) {
            for(int co = 0; co <= s1; co++) {
                for(auto p : dp1[co]) {
                    ll su = p.first;
                    if(su > x)
                        continue;
                    ll ta = x - su;
                    for(int co2 = 0; co2 <= s2; co2++) {
                        if(dp2[co2].count(ta)) {
                            ll re = (p.second * dp2[co2][ta]) % MOD;
                            re = (re * fac[co + co2]) % MOD;
                            re = (re * fac[n - co - co2]) % MOD;
                            ans -= re;
                            if(ans < 0)
                                ans += MOD;
                        }
                    }
                }
            }
        }
    }
    if(k >= 2) {
        ll t1 = ks[0], t2 = ks[1] - ks[0];
        for(int c11 = 0; c11 <= s1; c11++) {
            for(int c21 = 0; c11 + c21 <= s1; c21++) {
                for(auto p : dp3[c11][c21]) {
                    ll su1 = p.first.first, su2 = p.first.second;
                    if(su1 > t1 || su2 > t2)
                        continue;
                    ll r1 = t1 - su1, r2 = t2 - su2;
                    if(!to.count({r1,r2}))
                        continue;
                    for(int c12 = 0; c12 <= s2; c12++) {
                        for(int c22 = 0; c12 + c22 <= s2; c22++) {
                            if(dp4[c12][c22].count({r1, r2})) {
                                ll re = (p.second * dp4[c12][c22][{r1, r2}]) % MOD;
                                re = (re * fac[c11 + c12]) % MOD;
                                re = (re * fac[c21 + c22]) % MOD;
                                re = (re * fac[n - c11 - c12 - c21 - c22]) % MOD;
                                ans += re;
                                if(ans >= MOD)
                                    ans -= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}