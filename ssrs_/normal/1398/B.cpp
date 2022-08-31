#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> L;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        cnt = 0;
      }
      if (s[j] == '1'){
        if (cnt == 0){
          L.push_back(0);
        }
        cnt++;
        L.back()++;
      }
    }
    sort(L.rbegin(), L.rend());
    int cnt2 = L.size();
    int ans = 0;
    for (int j = 0; j < cnt2; j += 2){
      ans += L[j];
    }
    cout << ans << endl;
  }
}