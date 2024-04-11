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
  map<string, set<string>> M;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    s = s.substr(7);
    for (int j = 0; j < sz(s); j++) {
      if (s[j] == '/') {
        M[s.substr(0, j)].insert(s.substr(j));
        goto en;
      }
    }
    M[s].insert("");
    en:;
  }
  map<set<string>, vector<string>> M2;
  for (auto p : M) {
    M2[p.y].pb(p.x);
  }
  int ans = 0;
  for (auto p : M2) {
    if (sz(p.y) > 1) {
      ans++;
    }
  }
  printf("%d\n", ans);
  for (auto p : M2) {
    if (sz(p.y) > 1) {
      for (auto s : p.y) {
        printf("http://%s ", s.c_str());
      }
      printf("\n");
    }
  }
  return 0;
}