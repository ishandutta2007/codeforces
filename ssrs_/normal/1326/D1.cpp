#include <bits/stdc++.h>
using namespace std;
string rev(string s){
  reverse(s.begin(), s.end());
  return s;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    string S1 = s;
    string S2 = rev(s);
    if (S1 == S2){
      cout << s << endl;
    } else {
      int p = 0;
      string T;
      while (S1[p] == S2[p]){
        T += S1[p];
        p++;
      }
      string T2 = rev(T);
      string s1max, s2max;
      string r1, r2;
      for (int j = p; j < s.size() - p; j++){
        r1 += S1[j];
        r2 += S2[j];
        if (r1 == rev(r1)){
          s1max = r1;
        }
        if (r2 == rev(r2)){
          s2max = r2;
        }
      }
      if (s1max.size() >= s2max.size()){
        T += s1max;
      } else {
        T += s2max;
      }
      T += T2;
      cout << T << endl;
    }
  }
}