#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int a;
  cin >> a;
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3));
  int t = h * 60 + m;
  int t2 = t + a;
  t2 %= 1440;
  string h2 = to_string(t2 / 60);
  string w2 = to_string(t2 % 60);
  if (h2.size() == 1){
    h2 = "0" + h2;
  }
  if (w2.size() == 1){
    w2 = "0" + w2;
  }
  cout << h2 << ":" << w2 << endl;
}