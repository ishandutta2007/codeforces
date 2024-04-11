#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    int cnt1 = 0;
    int a2 = a;
    while ((a2 | b) != b){
      a2++;
      cnt1++;
    }
    ans = min(ans, cnt1 + 1);
    int cnt2 = 0;
    int b2 = b;
    while ((a | b2) != b2){
      b2++;
      cnt2++;
    }
    ans = min(ans, cnt2 + 1);
    cout << ans << endl;
  }
}