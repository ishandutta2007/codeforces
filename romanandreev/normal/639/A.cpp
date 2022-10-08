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
  int n, k, q;   
  scanf("%d%d%d", &n, &k, &q);
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  set<pair<int, int>> S;
  vector<int> was(n);
  for (int it = 0; it < q; it++) {
    int tp, x;
    scanf("%d %d", &tp, &x);
    x--;
    if (tp == 1) {
      S.insert(mp(t[x], x));
      was[x] = 1;
      while (sz(S) > k) {
        auto p = *S.begin();
        was[p.y] = 0;
        S.erase(p);
      }
    } else {
      if (was[x]) {
        printf("YES\n");
      } else {
        printf("NO\n");        
      }
    }
  }
  return 0;
}