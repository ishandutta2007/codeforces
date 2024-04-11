#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> cnt(16, 0);
  for (int i = 0; i < n; i++){
    int s = 0;
    for (int j = 0; j < k; j++){
      int x;
      cin >> x;
      s += x << j;
    }
    cnt[s]++;
  }
  bool ok = false;
  if (cnt[0] > 0){
    ok = true;
  }
  for (int i = 0; i < 4; i++){
    if (cnt[1 << i] > 0){
      for (int j = 0; j < 16; j++){
        if ((j >> i & 1) == 0 && cnt[j] > 0){
          ok = true;
        }
      }
    }
  }
  for (int i = 0; i < 16; i++){
    if (cnt[i] > 0 && cnt[15 - i] > 0){
      ok = true;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}