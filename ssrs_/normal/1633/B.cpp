#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(2, 0);
    for (int j = 0; j < n; j++){
      cnt[s[j] - '0']++;
    }
    if (cnt[0] != cnt[1]){
      cout << min(cnt[0], cnt[1]) << endl;
    } else {
      cout << cnt[0] - 1 << endl;
    }
  }
}