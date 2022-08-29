#include <bits/stdc++.h>
using namespace std;
int INF = 1000;
bool is_square(int a){
  double b = sqrt((double) a);
  int c = b;
  if (c * c == a){
    return true;
  } else if ((c + 1) * (c + 1) == a){
    return true;
  } else if ((c - 1) * (c - 1) == a){
    return true;
  } else {
    return false;
  }
}
int main(){
  int n;
  cin >> n;
  string S = to_string(n);
  int L = S.size();
  int ans = INF;
  for (int i = 1; i < (1 << L); i++){
    string T = "";
    for (int j = 0; j < L; j++){
      if ((i >> j) & 1){
        T += S[j];
      }
    }
    if (T[0] == '0'){
      continue;
    }
    int x = stoi(T);
    if (is_square(x)){
      ans = min(ans, L - __builtin_popcount(i));
    }
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}