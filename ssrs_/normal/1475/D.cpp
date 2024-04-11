#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> a1, a2;
    for (int j = 0; j < n; j++){
      if (b[j] == 1){
        a1.push_back(a[j]);
      }
      if (b[j] == 2){
        a2.push_back(a[j]);
      }
    }
    sort(a1.begin(), a1.end(), greater<int>());
    sort(a2.begin(), a2.end(), greater<int>());
    int c1 = a1.size();
    vector<long long> S1(c1 + 1);
    S1[0] = 0;
    for (int j = 0; j < c1; j++){
      S1[j + 1] = S1[j] + a1[j];
    }
    int c2 = a2.size();
    vector<long long> S2(c2 + 1);
    S2[0] = 0;
    for (int j = 0; j < c2; j++){
      S2[j + 1] = S2[j] + a2[j];
    }
    if (S1[c1] + S2[c2] < m){
      cout << -1 << endl;
    } else {
      int ans = INF;
      for (int j = 0; j <= c1; j++){
        if (S1[j] + S2[c2] >= m){
          auto itr = lower_bound(S2.begin(), S2.end(), m - S1[j]);
          ans = min(ans, j + (int) (itr - S2.begin()) * 2);
        }
      }
      cout << ans << endl;
    }
  }
}