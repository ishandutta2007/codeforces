#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  if (S[n] % 2 != 0){
    cout << "NO" << endl;
  } else {
    bool ok = false;
    for (int i = 0; i <= n; i++){
      if (S[i] * 2 == S[n]){
        ok = true;
      }
    }
    set<long long> st1;
    for (int i = 1; i <= n; i++){
      st1.insert(a[i - 1]);
      long long x = (S[i] - (S[n] - S[i])) / 2;
      if (st1.count(x) == 1){
        ok = true;
      }
    }
    set<long long> st2;
    for (int i = n - 1; i >= 0; i--){
      st2.insert(a[i]);
      long long x = ((S[n] - S[i]) - S[i]) / 2;
      if (st2.count(x) == 1){
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