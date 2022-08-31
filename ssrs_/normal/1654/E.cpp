#include <bits/stdc++.h>
using namespace std;
const int B = 100;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mx = min(n, 2);
  for (int i = -B; i <= B; i++){
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[j] = a[j] - i * j;
    }
    unordered_map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[b[j]]++;
      mx = max(mx, mp[b[j]]);
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < min(i + 100000 / B + 1, n); j++){
      if ((a[j] - a[i]) % (j - i) == 0){
        int q = (a[j] - a[i]) / (j - i);
        if (abs(q) > B){
          int x = a[i];
          int cnt = 0;
          for (int k = i; k <= j; k++){
            if (a[k] == x){
              cnt++;
            }
            x += q;
          }
          mx = max(mx, cnt);
        }
      }
    }
  }
  cout << n - mx << endl;
}