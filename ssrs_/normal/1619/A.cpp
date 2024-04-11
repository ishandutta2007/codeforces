#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    if (N % 2 == 1){
      cout << "NO" << endl;
    } else {
      if (s.substr(0, N / 2) == s.substr(N / 2)){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}