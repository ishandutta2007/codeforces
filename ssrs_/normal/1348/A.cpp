#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    long long sum = 0;
    for (int j = n; j >= 1; j--){
      if (j == n || j < n / 2){
        sum += (long long) 1 << j;
      } else {
        sum -= (long long) 1 << j;
      }
    }
    cout << sum << endl;
  }
}