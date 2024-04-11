#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 1000000007;


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  int g = 1;
  for (int _ = 0; _ < 12; _++) {
    int i = rand() % n;
    i += 88005553537;
    i %= n;
    i += rand() % 1337;
    i %= n;
    i++;
    i %= n;
    vector<int> D;
    for (int x = 1; x * x <= A[i]; x++) {
      if (A[i] % x == 0) {
        D.pb(x);
        if (x * x != A[i]) {
          D.pb(A[i] / x);
        }
      }
    }
    sort(all(D));
    vector<int> c((int) D.size());
    map<int, int> who;
    for (int j = 0; j < (int) D.size(); j++) who[D[j]] = j;
    for (int j = 0; j < n; j++) {
      int gc = gcd(A[i], A[j]);
      c[who[gc]]++;
    }
    vector<int> cnt((int) D.size());
    for (int ik = 0; ik < (int) D.size(); ik++) {
      for (int j = ik; j >= 0; j--) {
        if (D[ik] % D[j] == 0) {
          cnt[j] += c[ik];
        }
      }
    }
    for (int j = 0; j < (int) D.size(); j++) {
      if (cnt[j] >= (n + 1) / 2) {
        g = max(g, D[j]);
      }
    }
  }
  cout << g << '\n';

}