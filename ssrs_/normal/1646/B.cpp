#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    bool ok = false;
    for (int j = 1; j * 2 + 1 <= n; j++){
      if (S[j + 1] < S[n] - S[n - j]){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}