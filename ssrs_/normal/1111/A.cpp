#include <bits/stdc++.h>
using namespace std;
bool is_vowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main(){
  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()){
    cout << "No" << endl;
  } else {
    int N = s.size();
    bool ok = true;
    for (int i = 0; i < N; i++){
      if (is_vowel(s[i]) != is_vowel(t[i])){
        ok = false;
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}