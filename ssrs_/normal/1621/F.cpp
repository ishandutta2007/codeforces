#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    if (cnt == 0){
      if (n == 1){
        cout << 0 << endl;
      } else {
        cout << a << endl;
      }
    } else {
      int A = 0, C = 0;
      for (int j = 0; j < n; j++){
        if (s[j] == '0'){
          if (j == 0){
            C++;
          } else if (s[j - 1] == '1'){
            C++;
          } else {
            A++;
          }
        }
      }
      vector<int> d(cnt - 1);
      for (int j = 0; j < cnt - 1; j++){
        d[j] = p[j + 1] - p[j] - 1;
      }
      sort(d.begin(), d.end());
      int sum = 0;
      int nonzero = 0;
      long long ans = 0;
      for (int j = 0; j < cnt; j++){
        if (sum >= j + 1){
          break;
        }
        if (A + C < j - 1){
          break;
        }
        long long res = (long long) b * j;
        res -= (long long) c * nonzero;
        res += (long long) a * (sum - nonzero);
        int A2 = A - (sum - nonzero);
        int C2 = C - nonzero;
        int rem = j + 1 - sum;
        int x = min(rem, A2);
        res += (long long) a * x;
        rem -= x;
        int R;
        if (j == 0){
          R = max(rem - 1, 0);
        } else {
          R = max(rem - 2, 0);
        }
        res -= (long long) c * R;
        ans = max(ans, res);
        if (j < cnt - 1){
          sum += d[j];
          if (d[j] > 0){
            nonzero++;
          }
        }
      }
      cout << ans << endl;
    }
  }
}