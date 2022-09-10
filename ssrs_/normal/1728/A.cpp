#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int j = 0; j < n; j++){
      cin >> cnt[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (cnt[j] > cnt[ans]){
        ans = j;
      }
    }
    cout << ans + 1 << endl;
  }  
}