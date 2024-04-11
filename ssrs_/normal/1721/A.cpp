#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<char> c(4);
    for (int j = 0; j < 4; j++){
      cin >> c[j];
    }
    vector<int> cnt(26, 0);
    for (int j = 0; j < 4; j++){
      cnt[c[j] - 'a']++;
    }
    sort(cnt.begin(), cnt.end(), greater<int>());
    if (cnt[0] == 4){
      cout << 0 << endl;
    } else if (cnt[0] == 3){
      cout << 1 << endl;
    } else if (cnt[0] == 2 && cnt[1] == 2){
      cout << 1 << endl;
    } else if (cnt[0] == 2 && cnt[1] == 1){
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
}