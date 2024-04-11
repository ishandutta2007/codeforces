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
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    int moves = 0;
    int prev = 0;
    deque<int> A;
    for (int j = 0; j < n; j++){
      A.push_back(a[j]);
    }
    int tot1 = 0;
    int tot2 = 0;
    while (1){
      if (sum <= prev){
        if (moves % 2 == 0){
          tot1 += sum;
          if (sum != 0){
            moves++;
          }
          break;
        } else {
          tot2 += sum;
          if (sum != 0){
            moves++;
          }
          break;
        }
      }
      if (moves % 2 == 0){
        int curr = 0;
        while (1){
          curr += A.front();
          tot1 += A.front();
          sum -= A.front();
          A.pop_front();
          if (curr > prev){
            prev = curr;
            moves++;
            break;
          }
        }
      } else {
        int curr = 0;
        while (1){
          curr += A.back();
          tot2 += A.back();
          sum -= A.back();
          A.pop_back();
          if (curr > prev){
            prev = curr;
            moves++;
            break;
          }
        }
      }
    }
    cout << moves << ' ' << tot1 << ' ' << tot2 << endl;
  }
}