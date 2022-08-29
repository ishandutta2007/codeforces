#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    vector<int> c(k);
    for (int j = 0; j < k; j++){
      cin >> c[j];
    }
    vector<int> fib = {1, 1};
    while (fib.back() < INF){
      int x = fib.back();
      int y = fib[fib.size() - 2];
      fib.push_back(x + y);
    }
    int cnt = fib.size();
    long long sum = 0;
    for (int j = 0; j < k; j++){
      sum += c[j];
    }
    int p = -1;
    for (int j = 0; j < cnt; j++){
      sum -= fib[j];
      if (sum == 0){
        p = j + 1;
        break;
      }
    }
    if (p == -1){
      cout << "NO" << endl;
    } else {
      vector<long long> A(k, 0), B(k, 0);
      for (int j = 0; j < k; j++){
        int c2 = c[j];
        for (int l = p - 1; l >= 1; l--){
          if (c2 >= fib[l]){
            c2 -= fib[l];
            A[j] |= (long long) 1 << l;
            l--;
          }
        }
        if (c2 > 0){
          A[j] = 0;
        }
        c2 = c[j] - 1;
        B[j] = 1;
        for (int l = p - 1; l >= 2; l--){
          if (c2 >= fib[l]){
            c2 -= fib[l];
            B[j] |= (long long) 1 << l;
            l--;
          }
        }
        if (c2 != 0){
          B[j] = 0;
        }
      }
      vector<long long> L(k + 1, 0);
      for (int j = 0; j < k; j++){
        if ((L[j] & A[j]) > 0 || A[j] == 0){
          L[j + 1] = 0;
          break;
        } else {
          L[j + 1] = L[j] | A[j];
        }
      }
      vector<long long> R(k + 1, 0);
      for (int j = k - 1; j >= 0; j--){
        if ((R[j + 1] & A[j]) > 0 || A[j] == 0){
          R[j] = 0;
          break;
        } else {
          R[j] = R[j + 1] | A[j];
        }
      }
      bool ok = false;
      for (int j = 0; j < k; j++){
        if (!(j > 0 && L[j] == 0) && !(j < k - 1 && R[j + 1] == 0) && B[j] > 0){
          if ((L[j] & B[j]) == 0 && (B[j] & R[j + 1]) == 0 && (L[j] & R[j + 1]) == 0){
            ok = true;
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
}