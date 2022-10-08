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
  int n, p;
  cin >> n >> p;
  p /= 2;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  ll res = 0;
  ll cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur = cur * 2 + (s[i] == "halfplus");
    res += s[i] == "halfplus";
  }
  cout << (cur * 2 - res) * p << endl;
  return 0;
}