#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] < 0) {
      p[i] = -p[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int L = 0, R = 0;
    for (int j = 0; j < n; ++j) {
      if (p[j] < p[i]) {
        ++(j < i ? L : R);
      }
    }
    ans += min(L, R);
  }
  cout << ans;
  return 0;
}