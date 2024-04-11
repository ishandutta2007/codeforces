#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string S;
    cin >> S;
    map<pair<pair<int, int>, pair<int, int>>, bool> M;
    int y = 0;
    int x = 0;
    int ans = 0;
    for (char c : S){
      int y2 = y;
      int x2 = x;
      if (c == 'N') y2++;
      if (c == 'S') y2--;
      if (c == 'W') x2--;
      if (c == 'E') x2++;
      if (M.count(make_pair(make_pair(x, y), make_pair(x2, y2))) || M.count(make_pair(make_pair(x2, y2), make_pair(x, y)))){
        ans += 1;
      } else {
        ans += 5;
        M[make_pair(make_pair(x, y), make_pair(x2, y2))] = true;
      }
      y = y2;
      x = x2;
    }
    cout << ans << endl;
  }
}