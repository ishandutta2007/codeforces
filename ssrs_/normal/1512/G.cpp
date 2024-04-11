#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> sum(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++){
    for (int j = i; j <= MAX; j += i){
      sum[j] += i;
    }
  }
  vector<int> mn(MAX + 1, -1);
  for (int i = 1; i <= MAX; i++){
    if (sum[i] <= MAX){
      if (mn[sum[i]] == -1){
        mn[sum[i]] = i;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int c;
    cin >> c;
    cout << mn[c] << "\n";
  }
}