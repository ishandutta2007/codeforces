#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> cnt(2, 0);
    vector<long long> sum(2, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j] % 2]++;
      sum[a[j] % 2] += a[j];
    }
    for (int j = 0; j < q; j++){
      int t, x;
      cin >> t >> x;
      int c = cnt[t];
      long long s = sum[t];
      cnt[t] -= c;
      sum[t] -= s;
      cnt[t ^ (x % 2)] += c;
      sum[t ^ (x % 2)] += s + (long long) x * c;
      cout << sum[0] + sum[1] << endl;
    }
  }
}