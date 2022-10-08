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
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  map<string, int> M;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    M[s] = i;
  }
  vector<pair<int, string>> ls;
  for (auto p : M) {
    ls.pb(mp(-p.y, p.x));
  }
  sort(all(ls));
  for (auto p : ls) {
    cout << p.y << endl;
  }
  return 0;
}