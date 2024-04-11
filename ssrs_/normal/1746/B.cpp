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
    vector<vector<int>> S(2, vector<int>(n + 1));
    S[0][0] = 0;
    S[1][0] = 0;
    for (int j = 0; j < n; j++){
      S[0][j + 1] = S[0][j];
      S[1][j + 1] = S[1][j];
      S[a[j]][j + 1]++;
    }
    int ans = INF;
    for (int j = 0; j <= n; j++){
      int c1 = S[1][j];
      int c0 = S[0][n] - S[0][j];
      ans = min(ans, max(c0, c1));
    }
    cout << ans << endl;
  }
}