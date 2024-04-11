#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<int> w(k);
    for (int j = 0; j < k; j++){
      cin >> w[j];
    }
    sort(w.begin(), w.end());
    vector<int> M(k);
    for (int j = 0; j < k; j++){
      M[j] = a[j];
      w[j]--;
    }
    vector<int> m(k);
    for (int j = 0; j < k; j++){
      m[j] = M[j];
    }
    int pos = 0;
    for (int j = k; j < n; j++){
      while (w[pos] == 0){
        pos++;
      }
      m[pos] = a[j];
      w[pos]--;
    }
    long long ans = 0;
    for (int j = 0; j < k; j++){
      ans += M[j];
      ans += m[j];
    }
    cout << ans << endl;
  }
}