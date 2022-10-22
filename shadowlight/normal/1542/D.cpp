#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> a;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == '+') {
      int x;
      cin >> x;
      a.pb(x);
    } else {
      a.pb(-1);
    }
  }

  int res = 0;

  for (int ind = 0; ind < n; ++ind) {
    int x = a[ind];
    if (x == -1) continue;
  
    vector<int> ways(n, 0);
    ways[0] = 1;
    for (int i = 0; i < n; ++i) {
      if (i == ind) continue;

      bool smaller = (mp(a[i], i) < mp(x, ind));
      vector<int> nways(n, 0);
      for (int j = 0; j < n; ++j) {
        add(nways[j], ways[j]);
        if (a[i] == -1) {
          if (!j) {
            if (i < ind) {
              add(nways[j], ways[j]);
            }
          } else {
            add(nways[j - 1], ways[j]);
          }
        } else {
          if (j + smaller < n) add(nways[j + smaller], ways[j]);
        }
      }
      ways = nways;
    }
    int now = 0;
    for (int i = 0; i < n; ++i) {
      add(now, ways[i]);
    }
    //cout << x << " " << now << endl;
    add(res, mult(now, x));
  }
  cout << res << "\n";

}