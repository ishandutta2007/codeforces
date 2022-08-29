#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 0; i < k; i++){
    n -= 2;
    if (n >= 0){
      ans += n * 2 + 1;
    }
  }
  cout << ans << endl;
}