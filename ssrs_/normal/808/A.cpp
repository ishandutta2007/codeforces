#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s = to_string(n);
  int m;
  int c;
  if (s[0] == '9'){
    m = 1;
    c = s.size();
  } else {
    m = s[0] - '0' + 1;
    c = s.size() - 1;
  }
  for (int i = 0; i < c; i++){
    m *= 10;
  }
  cout << m - n << endl;
}