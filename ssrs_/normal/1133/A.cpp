#include <bits/stdc++.h>
using namespace std;
int main(){
  int h1, m1;
  char c1;
  cin >> h1 >> c1 >> m1;
  int h2, m2;
  char c2;
  cin >> h2 >> c2 >> m2;
  int t1 = h1 * 60 + m1;
  int t2 = h2 * 60 + m2;
  int t = (t1 + t2) / 2;
  int h = t / 60;
  int m = t % 60;
  string H = to_string(h);
  string M = to_string(m);
  if (h < 10){
    H = "0" + H;
  }
  if (m < 10){
    M = "0" + M;
  }
  cout << H << ":" << M << endl;
}