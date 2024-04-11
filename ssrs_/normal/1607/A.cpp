#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string a;
    cin >> a;
    string s;
    cin >> s;
    vector<int> p(26);
    for (int j = 0; j < 26; j++){
      p[a[j] - 'a'] = j;
    }
    int N = s.size();
    int ans = 0;
    for (int j = 0; j < N - 1; j++){
      ans += abs(p[s[j + 1] - 'a'] - p[s[j] - 'a']);
    }
    cout << ans << endl;
  }
}