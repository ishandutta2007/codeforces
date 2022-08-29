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
    vector<int> a(n + 2);
    a[0] = 0;
    a[n + 1] = 0;
    for (int j = 1; j <= n; j++){
      cin >> a[j];
    }
    long long S = 0;
    for (int j = 0; j < n + 1; j++){
      S += abs(a[j + 1] - a[j]);
    }
    for (int j = 1; j <= n; j++){
      if (a[j] > a[j - 1] && a[j] > a[j + 1]){
        int d = min(a[j] - a[j - 1], a[j] - a[j + 1]);
        S -= d;
      }
    }
    cout << S << endl;
  }
}