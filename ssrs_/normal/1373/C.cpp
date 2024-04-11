#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    int cnt = 0;
    int mn = 0;
    long long ans = 0;
    vector<int> L;
    for (int j = 0; j < N; j++){
      if (s[j] == '+'){
        cnt++;
      } else {
        cnt--;
        if (cnt < mn){
          mn = cnt;
          ans += j + 1;
        }
      }
    }
    ans += N;
    cout << ans << endl;
  }
}