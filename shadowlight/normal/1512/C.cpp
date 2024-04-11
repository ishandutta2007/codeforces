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

void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  for (char c : s) {
    if (c == '1') {
      --b;
    } else if (c == '0') {
      --a;
    }
  }

  for (int i = 0; i < n / 2; ++i) {
      if (s[i] == s[n - 1 - i]) {
        if (s[i] != '?') continue;
        continue;
      } else {
        if (s[i] != '?' && s[n - 1 - i] != '?') {
          cout << "-1\n";
          return;
        }
        char c = s[i] + s[n - 1 - i] - '?';
        s[i] = s[n - 1 - i] = c;
        if (c == '1') {
          --b;
        } else {
          --a;
        }
    }
  }

  for (int i = 0; i < n / 2; ++i) {
      if (s[i] == s[n - 1 - i]) {
        if (s[i] != '?') continue;
        if (a >= 2) {
          a -= 2;
          s[i] = s[n - 1 - i] = '0';
        } else if (b >= 2) {
          b -= 2;
          s[i] = s[n - 1 - i] = '1';
        } else {
          cout << "-1\n";
          return;
        }
      }
  }

  if (n % 2 && s[n / 2] == '?') {
    if (a) {
      --a;
      s[n / 2] = '0';
    } else {
      --b;
      s[n / 2] = '1';
    }
  }

  if (a != 0 || b != 0) {
    cout << "-1\n";
    return;
  }
  cout << s << "\n";
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