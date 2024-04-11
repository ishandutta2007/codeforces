#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> mx(26, -1);
    for (int j = 0; j < N; j++){
      int p = s[j] - 'a';
      mx[p] = j;
    }
    int mn = N;
    for (int j = 0; j < 26; j++){
      if (mx[j] != -1){
        mn = min(mn, mx[j]);
      }
    }
    cout << s.substr(mn) << endl;
  }
}