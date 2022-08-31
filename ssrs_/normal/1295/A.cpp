#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string ans(n / 2, '1');
    if (n % 2 == 1){
      ans[0] = '7';
    }
    cout << ans << endl;
  }
}