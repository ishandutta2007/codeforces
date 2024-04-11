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
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  vector<int> cnt(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int l = 0; l < n; l++) {
    for (int j = 0; j < n; j++) {
      cnt[j] = 0;
    }
    pair<int, int> mx = mp(0, 0);
    for (int r = l; r < n; r++) {
      cnt[a[r]]++;
      mx = max(mx, mp(cnt[a[r]], -a[r]));
      ans[-mx.y]++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}