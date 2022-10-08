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
const int maxn = (int)2e5 + 10;
int n;
int a[maxn];
ll sum[maxn];
ld calc(int l1, int r1, int l2, int r2) {
  if (r1 - l1 > r2 - l2) {
    assert(r1 - l1 == r2 - l2 + 1);
    return (sum[r1] - sum[l1] + sum[r2] - sum[l2]) / (ld)(r1 - l1 + r2 - l2) - a[r1 - 1];
  } else {
    assert(r1 - l1 == r2 - l2);
    return (sum[r1] - sum[l1] + sum[r2] - sum[l2]) / (ld)(r1 - l1 + r2 - l2) - (a[r1 - 1] + a[l2]) / (ld)2;
  }  
}
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }  
  sort(a, a + n);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i - 1];
  }  
  pair<ld, pair<pair<int, int>, pair<int, int>>> ans(0, mp(mp(0, 1), mp(0, 0)));  
  for (int i = 1; i + 1 < n; i++) {
    int l = 1;
    int r = min(i, n - 1 - i);
    while (l < r) {
      int m1 = (l + r) / 2;
      int m2 = m1 + 1;
      ld f1 = calc(i - m1, i + 1, n - m1, n);
      ans = max(ans, mp(f1, mp(mp(i - m1, i + 1), mp(n - m1, n))));
      ld f2 = calc(i - m2, i + 1, n - m2, n);
      ans = max(ans, mp(f2, mp(mp(i - m2, i + 1), mp(n - m2, n))));      
      if (f1 < f2) {
        l = m1 + 1;
      } else {
        r = m2 - 1;
      }
    }
    {      
      int m1 = l;    
      ld f1 = calc(i - m1, i + 1, n - m1, n);
      ans = max(ans, mp(f1, mp(mp(i - m1, i + 1), mp(n - m1, n))));
    }
  }
  printf("%d\n", ans.y.x.y - ans.y.x.x + ans.y.y.y - ans.y.y.x);
  for (int i = ans.y.x.x; i < ans.y.x.y; i++) {
    printf("%d ", a[i]);
  }
  for (int i = ans.y.y.x; i < ans.y.y.y; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}