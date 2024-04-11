#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    int ans = 0;
    for (int j = 0; j < k; j++){
      if (p[j] >= k){
        ans++;
      }
    }
    cout << ans << endl;
  }
}