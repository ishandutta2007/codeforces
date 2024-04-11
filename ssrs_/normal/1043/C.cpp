#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  for (int i = 0; i < N - 1; i++){
    if (s[i] != s[i + 1]){
      cout << 1 << ' ';
    } else {
      cout << 0 << ' ';
    }
  }
  if (s[N - 1] == 'a'){
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}