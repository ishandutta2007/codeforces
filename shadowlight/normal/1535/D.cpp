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



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int k;
  cin >> k;
  string s;
  cin >> s;
  reverse(all(s));
  int n = s.size();

  vector <int> sums(2 * n + 1);

  for (int i = sums.size() - 1; i >= n; --i) {
    sums[i] = 1;
  }

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      sums[i] = sums[2 * i + 1];
    } else if (s[i] == '0') {
      sums[i] = sums[2 * i + 2];
    } else {
      sums[i] = sums[2 * i + 1] + sums[2 * i + 2];
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int p;
    char c;
    cin >> p >> c;
    --p;
    p = (n - 1) - p;
    s[p] = c;

    while (true) {
      int i = p;
      if (s[i] == '1') {
        sums[i] = sums[2 * i + 1];
      } else if (s[i] == '0') {
        sums[i] = sums[2 * i + 2];
      } else {
        sums[i] = sums[2 * i + 1] + sums[2 * i + 2];
      }
      if (!p) break;
      p = (p - 1) / 2;
    }
    cout << sums[0] << "\n";
  }

}