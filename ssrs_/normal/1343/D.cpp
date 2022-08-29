#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int X = k * 2;
    vector<int> d(X + 2, 0);
    for (int j = 0; j < n / 2; j++){
      int A = a[j];
      int B = a[n - j - 1];
      d[2] += 2;
      d[min(A, B) + 1] -= 1;
      d[A + B] -= 1;
      d[A + B + 1] += 1;
      d[max(A, B) + k + 1] += 1;
    }
    for (int j = 0; j < X + 1; j++){
      d[j + 1] += d[j];
    }
    int ans = INF;
    for (int j = 2; j <= X; j++){
      ans = min(ans, d[j]);
    }
    cout << ans << endl;
  }
}