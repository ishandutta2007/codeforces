#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    string ans;
    int p1 = 0, p2 = 0;
    int c = 0, cnt = 0;
    while (p1 < s1.size() && p2 < s2.size()){
      bool t1 = false;
      if (s1[p1] < s2[p2]){
        if (!(c == 0 && cnt == k)){
          t1 = true;
        }
      } else {
        if (c == 1 && cnt == k){
          t1 = true;
        }
      }
      if (t1){
        ans += s1[p1];
        p1++;
        if (c == 0){
          cnt++;
        } else {
          c = 0;
          cnt = 1;
        }
      } else {
        ans += s2[p2];
        p2++;
        if (c == 1){
          cnt++;
        } else {
          c = 1;
          cnt = 1;
        }
      }
    }
    cout << ans << endl;
  }
}