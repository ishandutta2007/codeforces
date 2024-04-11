#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
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
    vector<long long> dp1(n + 1, - INF);
    vector<long long> dp2(n + 1, - INF);
    dp2[0] = 0;
    for (int j = 0; j < n; j++){
      dp1[j + 1] = max(dp1[j], dp2[j] + a[j]);
      dp2[j + 1] = max(dp2[j], dp1[j] - a[j]);
    }
    cout << max(dp1[n], dp2[n]) << endl;
  }
}