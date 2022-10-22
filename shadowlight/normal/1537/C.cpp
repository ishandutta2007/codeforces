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
  int n;
  cin >> n;
  vector <int> h(n);
  set <int> q;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    q.insert(h[i]);
  }
  sort(all(h));
  int pp = 0;
  int dist = h.back() - h[0];
  for (int i = 1; i < n; ++i) {
    if (h[i] - h[i - 1] < dist) {
      dist = h[i] - h[i - 1];
      pp = i;
    }
  }
  for (int i = pp; i < n; ++i) {
    cout << h[i] << " ";
  }
  for (int i = 0; i < pp; ++i) {
    cout << h[i] << " ";
  }
  cout << "\n";
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