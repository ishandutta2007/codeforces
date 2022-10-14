#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> C[i];
    B[i] = A[i] + C[i];
    sum += C[i];
  }

  vector<pair<int, int>> ev;
  for (int i = 0; i < n; i++) {
    ev.pb({A[i], 1});
    ev.pb({B[i] + 1, -1});
  }
  int sas = 0;
  sort(all(ev));
  int l = 1e12;
  int b = 0;
  for (auto x : ev) {
    if (b == 0) {
      sas += max(0LL, x.first - l + 1);
    }
    b += x.second;
    l = x.first;
  }
  sum += sas;
  cout << sum << '\n';

}