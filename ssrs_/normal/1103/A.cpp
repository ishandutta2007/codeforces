#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++){
    if (s[i] == '0'){
      if (cnt[0] % 2 == 0){
        cout << 3 << ' ' << 4 << endl;
      } else {
        cout << 1 << ' ' << 4 << endl;
      }
    } else {
      if (cnt[1] % 2 == 0){
        cout << 1 << ' ' << 1 << endl;
      } else {
        cout << 1 << ' ' << 3 << endl;
      }
    }
    cnt[s[i] - '0']++;
  }
}