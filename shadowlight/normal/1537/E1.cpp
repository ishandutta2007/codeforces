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

vector<int> zfunc(string& s) {
  int n = s.size();
  vector <int> z(n, 0);
  int l = -1, r = -1;
  for (int i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  s = s + s;
  n  = s.size();

  auto z = zfunc(s);

  int pos = n;
  int fsymb = n;
  char symb = 'z';

  for (int i = 1; i < n; ++i) {
      int d = z[i];
      if (i + d < n && s[i + d] > s[d]) {
        if (fsymb > i + d || (fsymb == i + d && symb > s[d])) {
          fsymb = i + d;
          symb = s[d];
          pos = i;
        }
      }
  }

  while (s.size() > pos) {
    s.pop_back();
  }

  while (s.size() <= k) {
    s += s;
  }

  while (s.size() > k) {
    s.pop_back();
  }

  cout << s << "\n";

}