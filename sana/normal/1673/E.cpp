#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }


int fac[1100010];
int ans[1100010];

ll fac2(ll k) {
    ll cnt = 0;
    ll pot = 2;
    while (pot <= k) {
        cnt += k / pot;
        pot <<= 1;
    }
    return cnt;
}

int C(int n, int k) {
    return k<=n && fac[n] <= fac[n-k] + fac[k];
}

int pre[27][1100000];

void solve()
{
    memset(ans,0,sizeof(ans));
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int operators = n-1;
    
    for (int i = 0; i <= (1LL<<20); i++) fac[i] = fac2(i); 
    
    int delta = max(0, n-25);
    for (int i = max(0, n-25); i <= n; i++) {
        for (int j = (1LL<<20)+1; j >= 0; j--) {
            pre[i - delta][j] = C(i, j) ^ pre[i-delta][j+1];
        }
    }
    
    for (int le = 0; le < n; le++) {
        ll prod = a[le];
        for (int ri = le; ri < n; ri++) {
            if (ri > le) {
                if (a[ri] > 20) break;
                prod = (prod * (1LL<<a[ri]));
            }
            if (prod >= (1LL<<20)) break;
            
            int used_xor = (le != 0) + (ri != n-1);
            int fixed = (ri-le) + used_xor;
            
            dbg(le,ri,prod,operators-fixed,k-used_xor,pre[(operators-fixed)-delta][k-used_xor]);
            if (pre[(operators - fixed) - delta][max(0, k - used_xor)]) ans[prod] ^= 1;
        }
    }
    
    bool fi = false;
    for (int i = (1LL<<20)-1; i >= 0; i--) {
        if (ans[i] == 0 && !fi) continue;
        fi = true;
        pr(ans[i]);
    }
    if (!fi) pr(0);
    ps();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}