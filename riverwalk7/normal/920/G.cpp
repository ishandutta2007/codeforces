#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath> 
#include <assert.h>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define fname ""
#define INF 2147483647
#define MOD 1000000007
#define mp make_pair
#define F first
#define S second
#define sc scanf
#define all(x) x.begin(), x.end()
#define size(x) int(x.size())
#define pr printf
#define deb(x) cerr << "[ " << #x << " = " << x << " ]"
#define pb push_back
#define ex exit(0)
#define y1 y4

typedef long long ll;
typedef unsigned long long ull;

const int N = 100500;

vector <int> a;

ll getd(ll l, ll r, ll x) {
    return (r / x) - ((l - 1) / x);
}

ll get(ll l, ll r) {
    ll ans = 0;
    for (int mask = 1; mask < (1 << size(a)); mask++) {
        ll d = 1;
        int cnt = 0;
        for (int i = 0; i < size(a); i++) {
             if (mask & (1 << i)) d *= a[i], cnt++;
        }
        if (cnt % 2 == 1) {
           ans += getd(l, r, d);
        } else ans -= getd(l, r, d);
    }
    return ans;
}

int main() {
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);
    #endif
    int test;
    cin >> test;
    while (test--) {
          ll x, p, k;
          cin >> x >> p >> k;
          a.clear();    
          for (ll i = 2; i <= sqrt(p); i++) {
              if (p % i == 0) {
                 a.pb(i);
                 while (p % i == 0) {
                       p /= i;                 
                 }              
              }          
          }
          if (p > 1) a.pb(p);
          ll l = x + 1;
          x++;
          ll r = ll(2e9);
          ll ans = -1;
          while (l <= r) {
                ll mid = (l + r) / 2;
                if ((mid - x + 1) - get(x, mid) < k) {
                   l = mid + 1;                                
                } else {
                ans = mid;
                   r = mid - 1;
                }                        
          }
          if (ans == -1) assert(0);
          cout << ans << endl;
    }
    #ifndef ONLINE_JUDGE
       cerr << clock() << " ms";
    #endif
    return 0;
}