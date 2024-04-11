#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    bool ok = true;
    for (int j = 0; j < N; j++){
      char c = 'a' + (N - 1 - j);
      if (s.front() == c){
        s.erase(s.begin());
      } else if (s.back() == c){
        s.pop_back();
      } else {
        ok = false;
        break;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}