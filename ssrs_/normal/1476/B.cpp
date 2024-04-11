#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    long long ans = 0;
    long long sum = 0;
    for (int j = 0; j < n; j++){
      if (j > 0){
        long long M = ((long long) p[j] * 100 + k - 1) / k;
        ans = max(ans, M - sum);
      }
      sum += p[j];
    }
    cout << ans << endl;
  }
}