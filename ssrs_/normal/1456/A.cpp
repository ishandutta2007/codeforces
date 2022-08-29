#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, p, k;
    cin >> n >> p >> k;
    p--;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    vector<int> cnt(n);
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        cnt[j] = 0;
      } else {
        cnt[j] = 1;
      }
    }
    for (int j = n - 1 - k; j >= 0; j--){
      cnt[j] += cnt[j + k];
    }
    int ans = INF;
    for (int j = p; j < n; j++){
      ans = min(ans, cnt[j] * x + (j - p) * y);
    }
    cout << ans << endl;
  }
}