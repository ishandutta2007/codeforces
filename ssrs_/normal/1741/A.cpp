#include <bits/stdc++.h>
using namespace std;
int f(string s){
  if (s == "M"){
    return 0;
  } else if (s.back() == 'L'){
    return s.size();
  } else {
    return -(int) s.size();
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string a, b;
    cin >> a >> b;
    int x = f(a);
    int y = f(b);
    if (x < y){
      cout << '<' << endl;
    } else if (x > y){
      cout << '>' << endl;
    } else {
      cout << '=' << endl;
    }
  }
}