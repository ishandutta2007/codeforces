#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 998244353;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
lint power(lint x, lint n, lint mod) {
  lint ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    lint D;
    cin >> D;
    vector<lint> primes;
    for(lint i = 2; i*i<=D; i++) {
        if(D%i == 0) {
            primes.push_back(i);
            while(true) {
                D /= i;
                if(D%i != 0) break;
            }
        }
    }
    vector<lint> frac(100000);
    frac[0] = 1;
    FOR(i, 1, 100000) {
        frac[i] = frac[i-1] * i % MOD;
    }
    if(D != 1) primes.push_back(D);
    int Q;
    cin >> Q;
    REP(q, Q) {
        lint u, v;
        cin >> u >> v;
        vector<lint> unum(primes.size());
        REP(i, primes.size()) {
            if(u%primes[i] == 0) {
                while(true) {
                    u /= primes[i];
                    unum[i]++;
                    if(u%primes[i] != 0) break;
                }
            }
        }
        vector<lint> vnum(primes.size());
        REP(i, primes.size()) {
            if(v%primes[i] == 0) {
                while(true) {
                    v /= primes[i];
                    vnum[i]++;
                    if(v%primes[i] != 0) break;
                }
            }
        }
        lint num = 0;
        vector<lint> diff;
        REP(i, primes.size()) {
            if(unum[i] != min(unum[i], vnum[i])) {
                num += unum[i] - min(unum[i], vnum[i]);
                diff.push_back(unum[i] - min(unum[i], vnum[i]));
            }
        }
        lint ans1 = frac[num];
        REP(i, diff.size()) {
            ans1 = ans1 * power(frac[diff[i]], MOD-2, MOD) % MOD;
        }
        num = 0;
        diff.clear();
        REP(i, primes.size()) {
            if(vnum[i] != min(unum[i], vnum[i])) {
                num += vnum[i] - min(unum[i], vnum[i]);
                diff.push_back(vnum[i] - min(unum[i], vnum[i]));
            }
        }
        lint ans2 = frac[num];
        REP(i, diff.size()) {
            ans2 = ans2 * power(frac[diff[i]], MOD-2, MOD) % MOD;
        }
        cout << ans1*ans2%MOD << "\n";
    }
}