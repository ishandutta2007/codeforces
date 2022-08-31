#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  if (s == "0"){
    cout << 0 << endl;
  } else {
    int N = s.size();
    int cnt = 0;
    for (int i = 0; i < N; i++){
      if (s[i] == '1'){
        cnt++;
      }
    }
    int ans = (s.size() + 1) / 2;
    if (s.size() % 2 == 1 && cnt == 1){
      ans--;
    }
    cout << ans << endl;
  }
}