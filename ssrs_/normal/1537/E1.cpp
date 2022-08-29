#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t;
  t += s[0];
  for (int i = 2; i <= n; i++){
    string s2 = s.substr(0, i);
    if (s2 + t < t + s2){
      t = s2;
    }
  }
  int l = t.size();
  for (int i = 0; i < k; i++){
    cout << t[i % l];
  }
  cout << endl;
}