#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n),  b(n);
    for (int j = 0; j < n; j++){
      cin >> a[j] >> b[j];
      a[j]--;
      b[j]--;
    }
    vector<int> cnt1(n, 0), cnt2(n, 0);
    for (int j = 0; j < n; j++){
      cnt1[a[j]]++;
      cnt2[b[j]]++;
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += (long long) (cnt1[a[j]] - 1) * (cnt2[b[j]] - 1);
    }
    long long all = (long long) n * (n - 1) * (n - 2) / 6;
    cout << all - sum << endl;
  }
}