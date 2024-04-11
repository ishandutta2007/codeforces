#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int t = 0, ans = INF;
  for (int i = 1; i <= 100; i++){
    int sum = 0;
    for (int j = 0; j < n; j++){
      if (a[j] < i - 1){
        sum += i - 1 - a[j];
      }
      if (a[j] > i + 1){
        sum += a[j] - (i + 1);
      }
    }
    if (sum < ans){
      t = i;
      ans = sum;
    }
  }
  cout << t << ' ' << ans << endl;
}