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
  int c2, c3;
  cin >> c2 >> c3;
  int l = max({c2 * 2, c3 * 3, (c2 + c3) * 3 / 2});
  int r = l + 6;
  while (l < r) {
    int m = (l + r) / 2;
    int f2 = c2 - min(c2, m / 2 - m / 6);
    int f3 = c3 - min(c3, m / 3 - m / 6);
    if (f2 + f3 <= m / 6) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << endl;
  return 0;
}