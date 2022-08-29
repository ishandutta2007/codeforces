#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int h;
    char c;
    int m;
    int x;
    cin >> h >> c >> m >> x;
    int T = h * 60 + m;
    vector<bool> used(1440, false);
    used[T] = true;
    while (true){
      T += x;
      T %= 1440;
      if (used[T]){
        break;
      }
      used[T] = true;
    }
    int ans = 0;
    for (int j = 0; j < 1440; j++){
      if (used[j]){
        int hh = j / 60, mm = j % 60;
        if (mm / 10 == hh % 10 && mm % 10 == hh / 10){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}