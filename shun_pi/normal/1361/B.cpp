#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        lint n, p;
        cin >> n >> p;
        vector<lint> k(n);
        REP(i, n) cin >> k[i];
        map<lint, lint> mp;
        REP(i, n) mp[k[i]]++;
        lint diff = 0;
        auto itr = prev(mp.end(), 1);
        bool mode = false;
        lint need = 1;
        lint lastkey = -1;
        while(true) {
            lint key = itr->first;
            lint val = itr->second;
            
            if(mode) {
                lint cnt = lastkey - key;
                while(cnt > 0 && need <= n) {
                    if(p == 1) break;
                    need *= p;
                    cnt--;
                }
            }
            //cout << key << " " << val << " " << need << " " << diff << endl;
            if(!mode) {
                if(val%2 != 0) {
                    mode = true;
                    diff = power(p, key, MOD);
                    need = 1;
                }
            } else {
                if(val >= need) {
                    diff = (diff - power(p, key, MOD) * need % MOD + MOD) % MOD;
                    mp[key] -= need;
                    itr++;
                    mode = false;
                    assert(diff == 0);
                } else {
                    diff = (diff - power(p, key, MOD) * val % MOD + MOD) % MOD;
                    need -= val;
                }
                
            }
            lastkey = key;
            if(itr == mp.begin()) break;
            itr--;
        }
        cout << diff << "\n";
    }
}