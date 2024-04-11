#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef double ld;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define next next_fdsgd
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define TASK "a"
const int maxn = (int)1e6 + 10;
ll ans[maxn];
set<pair<ll, int> > end_t;
void empty(ll st) {
  while (sz(end_t) > 0 && end_t.begin()->x <= st) {
    pair<ll, int> lw = *end_t.begin();
    end_t.erase(lw);
    ans[lw.y] = lw.x;
  }
}
int main() {
  #ifdef DEBUG
  freopen(TASK".in", "r", stdin);
  freopen(TASK".out", "w", stdout);
  #endif
  int n, k;
  scanf("%d %d", &n, &k);  
  ll s0 = 0;
  for (int i = 0; i < n; i++) {
    int s, m;
    scanf("%d %d", &s, &m);
    ll st = s;
    st = max(st, s0);
    empty(st);
    if (sz(end_t) == k) {
      st = max(st, end_t.begin()->x);
    }
    empty(st);
    assert(sz(end_t) < k);
    end_t.insert(mp(st + m, i));
    s0 = st;
  }
  empty((ll)1e18);
  for (int i = 0; i < n; i++) {
    printf("%I64d\n", ans[i]);
  }
  
  return 0; 
}