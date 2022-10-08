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

void solve() {
  int n;
  set<string> S;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (S.find(s) != S.end()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    S.insert(s);
  }
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}