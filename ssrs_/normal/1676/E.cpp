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
    sort(a.begin(), a.end(), greater<int>());
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    for (int j = 0; j < q; j++){
      int x;
      cin >> x;
      if (x > S[n]){
        cout << -1 << "\n";
      } else {
        cout << lower_bound(S.begin(), S.end(), x) - S.begin() << "\n";
      }
    }
  }
}