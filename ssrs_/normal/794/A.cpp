#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (b < x[i] && x[i] < c){
      ans++;
    }
  }
  cout << ans << endl;
}