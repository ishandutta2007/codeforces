#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string T;
    cin >> T;
    T.insert(T.begin(), '.');
    vector<int> mn(n + 1, INF);
    for (int j = 1; j <= n; j++){
      for (int k = j; k <= n; k += j){
        if (T[k] == '0'){
          mn[k] = min(mn[k], j);
        } else {
          break;
        }
      }
    }
    long long ans = 0;
    for (int j = 1; j <= n; j++){
      if (T[j] == '0'){
        ans += mn[j];
      }
    }
    cout << ans << endl;
  }
}