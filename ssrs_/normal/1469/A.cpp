#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    if (s.size() % 2 == 1 || s.front() == ')' || s.back() == '('){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}