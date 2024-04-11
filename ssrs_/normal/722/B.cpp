#include <bits/stdc++.h>
using namespace std;
vector<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y'};
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  string a;
  getline(cin, a);
  bool ok = true;
  for (int i = 0; i < n; i++){
    string s;
    getline(cin, s);
    int m = s.size();
    int cnt = 0;
    for (int j = 0; j < m; j++){
      for (int k = 0; k < 6; k++){
        if (s[j] == vowel[k]){
          cnt++;
        }
      }
    }
    if (cnt != p[i]){
      ok = false;
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}