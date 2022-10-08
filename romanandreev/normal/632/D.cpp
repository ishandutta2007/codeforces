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

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> res(m + 1);  
  vector<int> cnt(m + 1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] <= m) {
      cnt[a[i]]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j * i <= m; j++) {
      res[j * i] += cnt[i];
    }
  }
  int mx = 1;
  for (int i = 1; i <= m; i++) {
    if (res[i] > res[mx]) {
      mx = i;
    }
  }
  vector<int> ans;
  ll r = 1;
  for (int i = 0; i < n; i++) if (mx % a[i] == 0) {
    ans.pb(i);
    r = r * a[i] / __gcd(r, (ll)a[i]);
  }
  printf("%d %d\n", (int)r, sz(ans));
  for (auto x : ans) {
    printf("%d ", x + 1);
  }
  return 0;
}