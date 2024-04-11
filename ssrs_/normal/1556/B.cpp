#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
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
    vector<int> p1;
    for (int j = 0; j < n; j++){
      if (a[j] % 2 == 0){
        p1.push_back(j);
      }
    }
    long long ans = INF;
    for (int j = 0; j < 2; j++){
      vector<int> p2;
      for (int k = j; k < n; k += 2){
        p2.push_back(k);
      }
      if (p1.size() == p2.size()){
        int m = p1.size();
        long long sum = 0;
        for (int k = 0; k < m; k++){
          sum += abs(p1[k] - p2[k]);
        }
        ans = min(ans, sum);
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}