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
    vector<int> k(q);
    for (int j = 0; j < q; j++){
      cin >> k[j];
    }
    vector<int> mx(n + 1);
    vector<long long> S(n + 1);
    mx[0] = 0;
    S[0] = 0;
    for (int j = 0; j < n; j++){
      mx[j + 1] = max(mx[j], a[j]);
      S[j + 1] = S[j] + a[j];
    }
    for (int j = 0; j < q; j++){
      int p = upper_bound(mx.begin(), mx.end(), k[j]) - mx.begin();
      cout << S[p - 1];
      if (j < q - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}