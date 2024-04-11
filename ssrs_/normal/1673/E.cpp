#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> B(n);
  for (int i = 0; i < n; i++){
    cin >> B[i];
  }
  vector<bool> odd1(n, false);
  for (int i = max(n - 22, 0); i < n; i++){
    for (int j = max(k - 1, 0); j <= i; j++){
      if ((i & j) == j){
        odd1[i] = !odd1[i];
      }
    }
  }
  vector<bool> odd2(n, false);
  for (int i = max(n - 23, 0); i < n; i++){
    for (int j = max(k - 2, 0); j <= i; j++){
      if ((i & j) == j){
        odd2[i] = !odd2[i];
      }
    }
  }
  vector<bool> ans(1 << 20, false);
  if (k == 0){
    long long P = B[0];
    bool big = false;
    for (int i = 1; i < n; i++){
      if (B[i] >= 20){
        big = true;
        break;
      }
      P <<= B[i];
      if (P >= (1 << 20)){
        big = true;
        break;
      }
    }
    if (!big){
      ans[P] = !ans[P];
    }
  }
  if (n > 1){
    long long PL = B[0];
    if (odd1[n - 2]){
      ans[PL] = !ans[PL];
    }
    for (int i = 1; i < n - 1; i++){
      if (B[i] >= 20){
        break;
      }
      PL <<= B[i];
      if (PL >= (1 << 20)){
        break;
      }
      if (odd1[n - 2 - i]){
        ans[PL] = !ans[PL];
      }
    }
    for (int i = n - 1; i >= 1; i--){
      long long PR = B[i];
      bool big = false;
      for (int j = i + 1; j < n; j++){
        if (B[j] >= 20){
          big = true;
          break;
        }
        PR <<= B[j];
        if (PR >= (1 << 20)){
          big = true;
          break;
        }
      }
      if (big){
        break;
      }
      if (odd1[i - 1]){
        ans[PR] = !ans[PR];
      }
    }
  }
  for (int i = 1; i < n - 1; i++){
    long long P = B[i];
    if (odd2[n - 3]){
      ans[P] = !ans[P];
    }
    for (int j = i + 1; j < n - 1; j++){
      if (B[j] >= 20){
        break;
      }
      P <<= B[j];
      if (P >= (1 << 20)){
        break;
      }
      if (odd2[n - 3 - (j - i)]){
        ans[P] = !ans[P];
      }
    }
  }
  int p = 0;
  for (int i = 0; i < (1 << 20); i++){
    if (ans[i]){
      p = i;
    }
  }
  for (int i = p; i >= 0; i--){
    if (ans[i]){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}