#include <bits/stdc++.h>
using namespace std;
int add(int a, int b, int k){
  int ans = 0, m = 1;
  while (a > 0 || b > 0){
    int r = (a + b) % k;
    ans += m * r;
    m *= k;
    a /= k;
    b /= k;
  }
  return ans;
}
int sub(int a, int b, int k){
  int ans = 0, m = 1;
  while (a > 0 || b > 0){
    int r = (a + k - b % k) % k;
    ans += m * r;
    m *= k;
    a /= k;
    b /= k;
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    cout << 0 << endl;
    int r;
    cin >> r;
    if (r == 0){
      for (int j = 0; j < n - 1; j++){
        int y;
        if (j % 2 == 0){
          y = sub(j, j + 1, k);
        } else {
          y = sub(j + 1, j, k);
        }
        cout << y << endl;
        cin >> r;
        if (r == 1){
          break;
        }
      }
    }
  }
}