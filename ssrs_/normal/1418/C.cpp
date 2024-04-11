#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
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
    vector<int> dp0(n + 1, INF);
    vector<int> dp1(n + 1, INF);
    dp0[0] = 0;
    for (int j = 1; j <= n; j++){
      dp0[j] = min(dp0[j], dp1[j - 1]);
      dp1[j] = min(dp1[j], dp0[j - 1] + a[j - 1]);
      if (j > 1){
        dp0[j] = min(dp0[j], dp1[j - 2]);
        dp1[j] = min(dp1[j], dp0[j - 2] + a[j - 2] + a[j - 1]);
      }
    }
    cout << min(dp0[n], dp1[n]) << endl;
  }
}