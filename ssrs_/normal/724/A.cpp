#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<string> day = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  string s;
  cin >> s;
  string t;
  cin >> t;
  int x, y;
  for (int i = 0; i < 7; i++){
    if (s == day[i]){
      x = i;
    }
    if (t == day[i]){
      y = i;
    }
  }
  int d = (y - x + 7) % 7;
  if (d == 0 || d == 2 || d == 3){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}