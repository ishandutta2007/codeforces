#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    vector<int> S(a * b, 0);
    for (int j = 1; j < a * b; j++){
      if ((j % a) % b != (j % b) % a){
        S[j] = S[j - 1] + 1;
      } else {
        S[j] = S[j - 1];
      }
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++){
      long long l, r;
      cin >> l >> r;
      l--;
      long long ans = 0;
      ans += r / (a * b) * S[a * b - 1];
      ans += S[r % (a * b)];
      ans -= l / (a * b) * S[a * b - 1];
      ans -= S[l % (a * b)];
      cout << ans;
      if (j < q - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}