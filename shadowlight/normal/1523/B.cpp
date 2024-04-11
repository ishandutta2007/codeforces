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

  vector <int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto b = a;

  cout << (n / 2) * 6 << "\n";
  for (int i = 0; i < n; i += 2) {
    cout << "2 " << i + 1 << " " << i + 2 << "\n";
    cout << "1 " << i + 1 << " " << i + 2 << "\n";
    cout << "2 " << i + 1 << " " << i + 2 << "\n";
    cout << "2 " << i + 1 << " " << i + 2 << "\n";
    cout << "1 " << i + 1 << " " << i + 2 << "\n";
    cout << "2 " << i + 1 << " " << i + 2 << "\n";
  
    b[i + 1] -= b[i];
    b[i] += b[i + 1];
    b[i + 1] -= b[i];
    b[i + 1] -= b[i];
    b[i] += b[i + 1];
    b[i + 1] -= b[i];
  }

  for (int i = 0; i < n; ++i) {
    assert(b[i] == -a[i]);
    //cout << b[i] << " " << a[i] << endl;
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}