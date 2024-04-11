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
  int n, k, a, b, c, d;
  scanf("%d %d", &n, &k);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  vector<int> was(n + 1);
  vector<int> p(n);
  was[a] = 1;
  was[b] = 1;
  was[c] = 1;
  was[d] = 1;
  p[0] = a;
  p[n - 1] = b;
  p[1] = c;
  p[n - 2] = d;
  int it = 1;
  for (int i = 0; i < n; i++) {
    if (p[i] == 0) {
      while (was[it] == 1) {
        it++;
      }
      p[i] = it;
      was[it] = 1;
    }
  }
  if (n == 4) {
    printf("-1\n");
    return 0;
  }
  if (k < n - 1 + 2) {
    printf("-1\n");
    return 0;      
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
  printf("%d %d ", p[1], p[0]);
  for (int i = 2; i <= n - 3; i++) {
    printf("%d ", p[i]);
  }
  printf("%d %d\n", p[n - 1], p[n - 2]);
  return 0;
}