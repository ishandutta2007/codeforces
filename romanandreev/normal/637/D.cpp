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
vector<int> bc;
vector<pair<ll, int>> ls;
int n, m;
ll s, d;
void bct(int x) {
  if (x != 0) {
    bct(bc[x]);
  }
  ll r = ls[x].x + s;
  if (x > 0) {
    r -= min(ls[x].x, ls[bc[x]].x + s + d);
  }
  if (x > 0) {
    ll j = min(ls[x].x, ls[bc[x]].x + s + d) - (ls[bc[x]].x + s);
    printf("JUMP %d\n", (int)j);
  }
  printf("RUN %d\n", (int)r);
}
int main(){
  #ifdef home
  assert(freopen("a2.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> s >> d;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));  
  for (int i = 0; i < n; i++) {
    ll x = a[i] - s - 1;
    if ((i == 0 && x >= 0) || (i > 0 && x > a[i - 1])) {
      ls.pb(mp(x, i));
    }
  }
  if (a[0] - s - 1 < 0) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  set<pair<ll, int>> was;
  for (ll i = 1; i < sz(ls); i++) {
    was.insert(mp(ls[i].x, i));
  }
  queue<int> q;
  bc = vector<int>(sz(ls), -1);
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (ls[x].x + s + d > a[n - 1]) {
      bct(x);
      printf("JUMP %d\n", (int)(a[n - 1] + 1 - (ls[x].x + s)));
      if (m > a[n - 1] + 1) {
        printf("RUN %d\n", (int)(m - (a[n - 1] + 1)));
      }
      return 0;
    }
    while (1) {
      auto it = was.lower_bound(mp(ls[x].x + s + 1, -1));
      if (it == was.end()) {
        break;
      }
      if (it->x > ls[x].x + s + d) {
        if (a[ls[it->y].y - 1] >= ls[x].x + s + d) {
          break;
        }
      }
      q.push(it->y);
      bc[it->y] = x;
      was.erase(it);
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}