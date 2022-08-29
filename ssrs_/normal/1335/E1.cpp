#include <bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> S(n + 1, vector<int>(26, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 26; k++){
        S[j + 1][k] = S[j][k];
      }
      S[j + 1][a[j] - 1]++;
    }
    int m = 0;
    for (int L = 0; L <= n; L++){
      for (int R = L + 1; R <= n; R++){
        int a = 0;
        for (int k = 0; k < 26; k++){
          a = max(a, S[R][k] - S[L][k]);
        }
        int b = 0;
        for (int k = 0; k < 26; k++){
          b = max(b, min(S[L][k], S[n][k] - S[R][k]) * 2);
        }
        m = max(m, a + b);
      }
    }
    cout << m << endl;
  }
}