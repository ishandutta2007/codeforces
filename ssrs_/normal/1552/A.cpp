#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (s[j] != s2[j]){
        ans++;
      }
    }
    cout << ans << endl;
  }
}