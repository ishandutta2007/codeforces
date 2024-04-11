#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (b > a){
      ans++;
    }
    if (c > a){
      ans++;
    }
    if (d > a){
      ans++;
    }
    cout << ans << endl;
  }
}