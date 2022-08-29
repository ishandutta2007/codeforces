#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int ans = min({max(a * 2, b), a + b, max(b * 2, a)});
    cout << ans * ans << endl;
  }
}