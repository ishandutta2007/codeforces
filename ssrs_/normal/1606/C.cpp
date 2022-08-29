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
    vector<int> d(n, 1);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < a[j]; k++){
        d[j] *= 10;
      }
    }
    k++;
    long long s = 0;
    for (int j = 0; j < n - 1; j++){
      if (k > 0){
        int p = min(k, d[j + 1] / d[j] - 1);
        s += p * d[j];
        k -= p;
      }
    }
    if (k > 0){
      s += (long long) d[n - 1] * k;
    }
    cout << s << endl;
  }
}