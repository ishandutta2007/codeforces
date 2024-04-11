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
char s[1000000];
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  int n;
  scanf("%d", &n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }  
  scanf("%s", s);
  vector<ll> sum0(n + 1);
  vector<ll> sum1(n + 1);
  for (int i = 0; i < n; i++) {
    sum0[i + 1] = sum0[i] + p[i] * (s[i] == 'A' ? 1 : 0);
    sum1[i + 1] = sum1[i] + p[i] * (s[i] == 'A' ? 0 : 1);
  }
  ll ans = -(ll)1e18;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, sum0[i] + sum1[n] - sum1[i]);
    ans = max(ans, sum1[i] + sum0[n] - sum0[i]);
  }
  cout << ans << endl;
  return 0;
}