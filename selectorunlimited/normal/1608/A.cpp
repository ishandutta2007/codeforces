#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n);
    v[0] = 2;
    for (long long int i = 1; i < n; i++) {
      v[i] = v[i - 1] + 1;
    }
    for (long long int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}