#include <bits/stdc++.h>
using namespace std;
int INF = 10000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int j = 0; j < n; j++){
      cnt[s[j] - 'a']++;
    }
    int ans = 0;
    for (int j = 1; j <= n; j++){
      int tmp1 = j / gcd(k, j);
      int tmp2 = 0;
      for (int c : cnt){
        tmp2 += c / tmp1;
      }
      if (tmp2 >= gcd(k, j)){
        ans = j;
      }
    }
    cout << ans << endl;
  }
}