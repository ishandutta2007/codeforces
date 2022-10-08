#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

const int maxn = 1 << 14;
int cnt[maxn];
int bit[maxn];

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for (int i = 0; i < maxn; i++) {
    bit[i] = __builtin_popcount(i);
  }
  ll ans = 0;
  for (int i = 0; i < maxn; i++) {
    for (int j = i; j < maxn; j++) {
      if (bit[i ^ j] == k) {
        if (i == j) {
          ans += cnt[i] * (ll)(cnt[i] - 1) / 2;
        } else {
          ans += cnt[i] * (ll)cnt[j];
        }
      }
    }
  }
  cout << ans << endl;
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  solve();
  return 0;
}