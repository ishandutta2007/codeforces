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
bool is_prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int poww(int x, int s, int md) {
  if (s == 0) return 1;
  ll res = poww(x, s / 2, md);
  res = (res * res) % md;
  if (s & 1) {
    res = (res * x) % md;    
  }
  return (int)res;
}
int obr(int x, int md) {
  return poww(x, md - 2, md);
}
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  srand((int)time(0));
  vector<int> ls;
  for (int M = (int)1e9 + rand(); sz(ls) <= 3; M++) {
    if (is_prime(M)) {
      ls.pb(M);
    }
  }
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n + 1);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> pw(sz(ls), 1);
  vector<int> val(sz(ls), 0);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < sz(pw); j++) {        
      val[j] = int((val[j] + (ll)pw[j] * a[i]) % ls[j]);
    }
    for (int j = 0; j < sz(pw); j++) {
      pw[j] = (pw[j] * 2) % ls[j];
    }
  }
  pw = vector<int>(sz(ls), 1);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    map<ll, int> cand;
    for (int j = 0; j < sz(pw); j++) {
      ll dc = ((ll)val[j] * obr(pw[j], ls[j])) % ls[j];
      bool good = false;
      for (int dx = -2; dx <= 2; dx++) {
        if (cand[dc + (ll)dx * ls[j]]++ == j) {
          good = true;
        }
      }
      if (!good) break;
    }            
    for (auto p : cand) {
      if (p.y == sz(ls)) {
        ll res = a[i] - p.x;
        if (abs(res) <= k && (i < n || (i == n && res != 0))) {
          ans++;
        }
        break;
      }
    }
    for (int j = 0; j < sz(pw); j++) {
      pw[j] = (pw[j] * 2) % ls[j];
    }
  }
  cout << ans << endl;
  return 0;
}