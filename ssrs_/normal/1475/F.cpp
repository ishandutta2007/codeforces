#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<string> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<vector<int>> c(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        int A = a[j][k] - '0';
        int B = b[j][k] - '0';
        c[j][k] = A ^ B;
      }
    }
    bool ok = true;
    for (int j = 1; j < n; j++){
      for (int k = 1; k < n; k++){
        if ((c[0][0] + c[0][k] + c[j][0] + c[j][k]) % 2 == 1){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}