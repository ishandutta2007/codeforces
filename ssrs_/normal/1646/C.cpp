#include <bits/stdc++.h>
using namespace std;
const int INF = 100;
int main(){
  vector<long long> fact;
  for (int i = 3; i <= 14; i++){
    long long P = 1;
    for (int j = 1; j <= i; j++){
      P *= j;
    }
    fact.push_back(P);
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    int ans = INF;
    for (int j = 0; j < (1 << 12); j++){
      long long n2 = n;
      for (int k = 0; k < 12; k++){
        if ((j >> k & 1) == 1){
          n2 -= fact[k];
        }
      }
      if (n2 >= 0){
        ans = min(ans, __builtin_popcount(j) + __builtin_popcountll(n2));
      }
    }
    cout << ans << endl;
  }
}