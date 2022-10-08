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
  cin >> n;
  vector<int> a(2 * n, 0);
  int l = 0;
  int r = n - 1;
  int k = 1;
  while (l <= r && k < n) {
    a[l] = k;
    a[r] = k;
    a[l + n] = k + 1;
    a[r + n - 1] = k + 1;
    l++;
    r--;    
    k += 2;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (a[i] == 0) {
      a[i] = n;
    }
    printf("%d ", a[i]);
  }

  return 0;
}