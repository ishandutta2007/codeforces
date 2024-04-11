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
    sort(a.begin(), a.end(), greater<int>());
    long long sum1 = 0, sum2 = 0;
    for (int j = 0; j < n; j++){
      if (j % 2 == 0){
        if (a[j] % 2 == 0){
          sum1 += a[j];
        }
      } else {
        if (a[j] % 2 == 1){
          sum2 += a[j];
        }
      }
    }
    if (sum1 > sum2){
      cout << "Alice" << endl;
    } else if (sum1 < sum2){
      cout << "Bob" << endl;
    } else {
      cout << "Tie" << endl;
    }
  }
}