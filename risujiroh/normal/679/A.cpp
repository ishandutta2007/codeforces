#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
  vector<bool> b(n / 3 + 1, true);
  vector<int> res{2, 3};
  for (int p = 5, d = 4; p * p <= n; p += d = 6 - d) if (b[p / 3])
    for (int i = p * p, di = p % 3 * 2 * p; i <= n; i += di = 6 * p - di)
      b[i / 3] = false;
  for (int p = 5, d = 4; p <= n; p += d = 6 - d) if(b[p / 3]) res.push_back(p);
  while (not res.empty() and res.back() > n) res.pop_back();
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  for (int p : {2, 3, 5, 7}) {
    cout << p * p << endl;
    string s;
    cin >> s;
    if (s == "yes") {
      cout << "composite" << endl;
      exit(0);
    }
  }
  auto ps = sieve(50);
  int cnt = 0;
  for (int p : ps) {
    cout << p << endl;
    string s;
    cin >> s;
    cnt += s == "yes";
  }
  if (cnt >= 2) {
    cout << "composite" << endl;
  } else {
    cout << "prime" << endl;
  }
}