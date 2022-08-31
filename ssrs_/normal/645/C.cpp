#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i];
    if (s[i] == '0'){
      S[i + 1]++;
    }
  }
  int tv = n, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    bool ok = false;
    for (int i = 0; i < n; i++){
      if (s[i] == '0'){
        if (S[min(i + mid + 1, n)] - S[max(i - mid, 0)] >= k + 1){
          ok = true;
        }
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}