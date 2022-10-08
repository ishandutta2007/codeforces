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
  ll n;
  cin >> n;
  ll l = 1;
  ll r = 2 * (ll)(sqrt(n) + 2);
  while (l < r) {
    ll m = (l + r) / 2;
    if (m * (m + 1) / 2 < n) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  l--;
  n -= l * (l + 1) / 2;
  cout << n << endl;
  return 0;
}