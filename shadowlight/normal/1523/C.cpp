#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

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

void print(vector<int>& a) {
    string s = "";
    for (int j = 0; j < (int) a.size(); ++j) {
      string t = "";
      int x = a[j];
      do {
        t += (char) (x % 10 + '0');
        x /= 10;
      } while (x);
      reverse(all(t));
      s += t;

      if (j + 1 != a.size()) {
        s += '.';
      }
    }
   cout << s << "\n";
}

void solve() {
  int n;
  cin >> n;

  int x;
  cin >> x;

  vector <vector<int>> res(1, {1});
  vector<bool> iterated(1, false);
  vector<bool> extended(1, false);

  print(res.back());

  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;

    while (res.size()) {
      if (x == 1 && !extended[res.size() - 1]) {
        extended[res.size() - 1] = true;
        res.pb(res.back());
        res.back().pb(x);
        break;
      }
      if (x == res.back().back() + 1 && !iterated[res.size() - 1]) {
        iterated[res.size() - 1] = true;
        res.pb(res.back());
        res.back().back() += 1;
        break;
      }
      iterated.pop_back();
      extended.pop_back();
      res.pop_back();
    }
    assert(res.size());
    print(res.back());
    iterated.pb(false);
    extended.pb(false);
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}