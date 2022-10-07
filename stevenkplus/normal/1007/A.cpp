#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ar.push_back(x);
  }

  sort(ar.begin(), ar.end());

  int k = 0;
  int m = 0;
  for (int i: ar) {
    while (k < ar.size() && i >= ar[k]) {
      ++k;
    }
    if (k < ar.size()) {
      ++k;
      ++m;
    }
  }

  cout << m << "\n";;
}