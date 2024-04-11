#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int j = 0; j < n * 2 - 1; j++){
      if (s.substr(j, 2) == "()"){
        cnt++;
      }
    }
    cout << n + 1 - cnt << "\n";
  }
}